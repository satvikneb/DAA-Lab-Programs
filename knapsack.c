#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N, W;

    if (scanf("%d", &N) != 1) return 0;

    int *values = (int *)malloc(N * sizeof(int));
    int *weights = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    scanf("%d", &W);

    int *dp = (int *)calloc(W + 1, sizeof(int));

    for (int i = 0; i < N; i++) {
        int curr_val = values[i];
        int curr_wt = weights[i];

        for (int w = W; w >= curr_wt; w--) {
            dp[w] = max(dp[w], dp[w - curr_wt] + curr_val);
        }
    }

