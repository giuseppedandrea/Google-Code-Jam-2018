/*
#Problem

Annie is a bus driver with a high-stress job. She tried to unwind by going on a Caribbean cruise, but that also turned out to be stressful, so she has recently taken up horseback riding.

Today, Annie is riding her horse to the east along a long and narrow one-way road that runs west to east. She is currently at kilometer 0 of the road, and her destination is at kilometer D; kilometers along the road are numbered from west to east.

There are N other horses traveling east on the same road; all of them will go on traveling forever, and all of them are currently between Annie's horse and her destination. The i-th of these horses is initially at kilometer Ki and is traveling at its maximum speed of Si kilometers per hour.

Horses are very polite, and a horse H1 will not pass (move ahead of) another horse H2 that started off ahead of H1. (Two or more horses can share the same position for any amount of time; you may consider the horses to be single points.) Horses (other than Annie's) travel at their maximum speeds, except that whenever a horse H1 catches up to another slower horse H2, H1 reduces its speed to match the speed of H2.

Annie's horse, on the other hand, does not have a maximum speed and can travel at any speed that Annie chooses, as long as it does not pass another horse. To ensure a smooth ride for her and her horse, Annie wants to choose a single constant "cruise control" speed for her horse for the entire trip, from her current position to the destination, such that her horse will not pass any other horses. What is the maximum such speed that she can choose?

# Input

The first line of the input gives the number of test cases, T; T test cases follow. Each test case begins with two integers D and N: the destination position of all of the horses (in kilometers) and the number of other horses on the road. Then, N lines follow. The i-th of those lines has two integers Ki and Si: the initial position (in kilometers) and maximum speed (in kilometers per hour) of the i-th of the other horses on the road.

# Output

For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the maximum constant speed (in kilometers per hour) that Annie can use without colliding with other horses. y will be considered correct if it is within an absolute or relative error of 10-6 of the correct answer. See the FAQ for an explanation of what that means, and what formats of real numbers we accept.

# Limits

1 ≤ T ≤ 100.
0 < Ki < D ≤ 10^9, for all i.
Ki ≠ Kj, for all i ≠ j. (No two horses start in the same position.)
1 ≤ Si ≤ 10000.
Time limit: 10 seconds per test set.
Memory limit: 1GB.

# Test set 1 (Visible)

1 ≤ N ≤ 2.

# Test set 2 (Hidden)

1 ≤ N ≤ 1000.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct horses Horses;

struct horses {
  long K;
  long S;
  float min_time;
};

int main(int argc, char const *argv[]) {
  int T;
  long D, N;
  float min_time;
  Horses *horses;

  scanf("%d", &T);

  for (size_t i = 0; i < T; i++) {
    scanf("%ld %ld", &D, &N);

    horses=(Horses *)malloc(N*sizeof(*horses));

    for (size_t j = 0; j < N; j++) {
      scanf("%ld %ld", &(horses[j].K), &(horses[j].S));
      horses[j].min_time=(float)(D-horses[j].K)/(float)(horses[j].S);
    }

    printf("Case #%d: ", i+1);

    min_time=0;
    for (size_t j = 0; j < N; j++) {
      if (horses[j].min_time>=min_time) {
        min_time=horses[j].min_time;
      }
    }
    printf("%f\n", (float)D/min_time);

    free(horses);
  }

  return 0;
}
