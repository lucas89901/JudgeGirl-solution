#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Variable {
  char name[33];
  int value;
} Variable;

int Find(Variable variables[], int size, char name[]) {
  for (int i = 0; i < size; ++i) {
    if (strcmp(variables[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}

bool IsNumber(char str[]) {
  for (int i = 0, size = strlen(str); i < size; ++i) {
    if (!isdigit(str[i])) {
      return false;
    }
  }
  return true;
}

int Calculate(Variable variables[], int variables_size, char *tokens[],
              int *index) {
  // fprintf(stderr, "%d %s\n", *index, tokens[*index]);
  if (*tokens[*index] == '(') {
    // fprintf(stderr, "expression\n");
    ++(*index);  // skip '('
    int answer;
    switch (*tokens[(*index)++]) {
      case '+':
        answer = Calculate(variables, variables_size, tokens, index) +
                 Calculate(variables, variables_size, tokens, index);
        break;
      case '-':
        answer = Calculate(variables, variables_size, tokens, index) -
                 Calculate(variables, variables_size, tokens, index);
        break;
      case '*':
        answer = Calculate(variables, variables_size, tokens, index) *
                 Calculate(variables, variables_size, tokens, index);
        break;
      case '/':
        answer = Calculate(variables, variables_size, tokens, index) /
                 Calculate(variables, variables_size, tokens, index);
        break;
    }
    ++(*index);  // skip ')'
    return answer;
  }
  if (IsNumber(tokens[*index])) {
    // fprintf(stderr, "number\n");
    return atoi(tokens[(*index)++]);
  }
  // fprintf(stderr, "variable\n");
  return variables[Find(variables, variables_size, tokens[(*index)++])].value;
}

int main() {
  char str[1000];
  fgets(str, 1000, stdin);
  // fprintf(stderr, "%s", str);

  Variable variables[50];
  int variables_size = 0;
  while (scanf("%s = %d", variables[variables_size].name,
               &variables[variables_size].value) != EOF) {
    ++variables_size;
  }

  char *tokens[1000];
  int tokens_size = 0;
  for (char *p = strtok(str, " \n"); p; p = strtok(NULL, " \n")) {
    tokens[tokens_size++] = p;
  }
  // for (int i = 0; i < tokens_size; ++i) {
  //   fprintf(stderr, "%s\n", tokens[i]);
  // }

  int index = 0;
  printf("%d\n", Calculate(variables, variables_size, tokens, &index));
  return 0;
}
