#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include "freqCalculator.h"

#define MAXF 10
#define LOWFREQTHRESHOLD 100
#define MAGNIFYFACTOR 20000
#define MAXSAMPLE 100000
#define MAXNOTE 1024

#define min(a, b) (a < b ? a : b)

typedef struct note
{
    int feqNum;
    double frequency[MAXF];
    double duration;
} Note;

typedef struct WAVheader
{
    char RIFF[4];
    int chunkSize;
    char wave[4];
    char format[4];
    int subChunkSize;
    short audioFormat;
    short numChannel;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char data[4];
    int dataSize;
} WAVHeader;

int genWAV(Note note[], int noteNum, FILE *fp, WAVHeader header)
{
    int dataSize = 0;
    const double PI = 3.1415926;

    for (int n = 0; n < noteNum; n++)
    {
        int sampleNum = note[n].duration * header.sampleRate;
        assert(sampleNum < MAXSAMPLE);
        printf("sample number %d\n", sampleNum);
        short int samples[MAXSAMPLE * 2] = {0};

        for (int f = 0; f < note[n].feqNum; f++)
        {
            double frequency = note[n].frequency[f];
            if (frequency < LOWFREQTHRESHOLD)
            {
                printf("warning, low frequency %lf\n", frequency);
                assert(note[n].feqNum == 1);
                short zero[MAXSAMPLE * 2] = {0};
                fwrite(zero, sizeof(short), 2 * sampleNum, fp);
                dataSize += sizeof(short) * 2 * sampleNum;
                break; /* get out of loop */
            }
            else
            {
                int samplePerCycle = header.sampleRate / (double)frequency;
                assert(samplePerCycle < sampleNum);
                printf("%d samples per cycle\n", samplePerCycle);
                double duration = note[n].duration;
                double delta = (2.0 * PI) / samplePerCycle;
                short sins[samplePerCycle];
                for (int s = 0; s < samplePerCycle; s++)
                {
                    sins[s] = (sin(delta * s) * MAGNIFYFACTOR) / note[n].feqNum;
                }
                int sindex = 0;
                while (sindex + 2 * samplePerCycle <= 2 * sampleNum)
                {
                    for (int s = 0; s < samplePerCycle; s++)
                    {
                        samples[sindex++] += sins[s];
                        samples[sindex++] += sins[s];
                    }
                }
                printf("%d samples added for freq %lf\n", sindex, frequency);
            }
        }
        fwrite(samples, sizeof(short), 2 * sampleNum, fp);
        dataSize += sizeof(short) * 2 * sampleNum;
    }
    return dataSize;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./genwav <input file> <output file>\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    assert(inputFile != NULL);

    FILE *outputFile = fopen(argv[2], "wb");
    assert(outputFile != NULL);

    WAVHeader header = {
        .RIFF = {'R', 'I', 'F', 'F'},
        .chunkSize = 0,
        .wave = {'W', 'A', 'V', 'E'},
        .format = {'f', 'm', 't', ' '},
        .subChunkSize = 16,
        .audioFormat = 1,
        .numChannel = 2,
        .sampleRate = 44100,
        .byteRate = 176400,
        .blockAlign = 4,
        .bitsPerSample = 16,
        .data = {'d', 'a', 't', 'a'},
        .dataSize = 0};

    int dataSize = 0;
    Note note[MAXNOTE];
    int beatPerSecond, numOfNotes;

    assert(fscanf(inputFile, "%d%d", &beatPerSecond, &numOfNotes) == 2);

    double durations[MAXNOTE];
    for (int i = 0; i < numOfNotes; i++)
    {
        assert(fscanf(inputFile, "%lf", &durations[i]) == 1);
    }

    char names[1024];
    assert(fscanf(inputFile, " %[^\n]", names) == 1);
    fclose(inputFile);

    double *frequencies = freqCalculate(names);

    for (int i = 0; i < numOfNotes; i++)
    {
        note[i].duration = (60.0 / beatPerSecond) * durations[i];
        note[i].feqNum = 1;
        note[i].frequency[0] = frequencies[i];
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);

    dataSize = genWAV(note, numOfNotes, outputFile, header);
    printf("dataSize = %d\n", dataSize);
    int chunkSize = dataSize + 36;
    printf("chunkSize = %d\n", chunkSize);
    fseek(outputFile, 4, SEEK_SET);
    fwrite(&chunkSize, sizeof(int), 1, outputFile);
    fseek(outputFile, 40, SEEK_SET);
    fwrite(&dataSize, sizeof(int), 1, outputFile);

    fclose(outputFile);
    return 0;
}
