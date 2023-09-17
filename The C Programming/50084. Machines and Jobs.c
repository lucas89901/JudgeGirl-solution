#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

typedef struct Job {
  int completion_time;
  int task_count;
  int task_machine[500];
  int task_time[500];
  int head_task;
} Job;

int main() {
  int N, M;
  scanf("%d%d", &N, &M);

  int machine_free[N];
  memset(machine_free, 0, sizeof(machine_free));
  Job jobs[M];
  for (int i = 0; i < M; ++i) {
    // Consider a job's arrival time as the completion time of a virtual task
    // before the first task.
    scanf("%d%d", &jobs[i].completion_time, &jobs[i].task_count);
    for (int j = 0; j < jobs[i].task_count; ++j) {
      scanf("%d%d", &jobs[i].task_machine[j], &jobs[i].task_time[j]);
    }
    jobs[i].head_task = 0;
  }

  while (true) {
    bool done = true;
    int candidate_job = -1;
    int candidate_completion_time = INT_MAX;
    for (int i = 0; i < M; ++i) {
      if (jobs[i].head_task == jobs[i].task_count) {
        continue;
      }
      done = false;

      int task_machine = jobs[i].task_machine[jobs[i].head_task];
      int completion_time =
          Max(machine_free[task_machine], jobs[i].completion_time) +
          jobs[i].task_time[jobs[i].head_task];

      if (candidate_job == -1 || completion_time < candidate_completion_time) {
        candidate_job = i;
        candidate_completion_time = completion_time;
      }
    }

    if (done) {
      break;
    }

    int task_machine =
        jobs[candidate_job].task_machine[jobs[candidate_job].head_task];
    machine_free[task_machine] = candidate_completion_time;
    jobs[candidate_job].completion_time = candidate_completion_time;
    ++jobs[candidate_job].head_task;
  }

  for (int i = 0; i < M; ++i) {
    printf("%d\n", jobs[i].completion_time);
  }
  return 0;
}
