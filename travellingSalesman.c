#include <stdio.h>
#include <limits.h>

#define INF 1000000000

int n;
int cost[20][20];
int dp[1 << 20][20];

int tsp(int mask, int pos) {
    // All cities have been visited
    if (mask == (1 << n) - 1) {
        if (cost[pos][0] == -1)
            return INF;
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INF;

    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city)) && cost[pos][city] != -1) {
            int next = tsp(mask | (1 << city), city);

            if (next != INF) {
                int value = cost[pos][city] + next;
                if (value < ans)
                    ans = value;
            }
        }
    }

    return dp[mask][pos] = ans;
}
