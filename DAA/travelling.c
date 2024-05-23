#include <stdio.h>
#include <limits.h>

#define MAX_N 15 // Maximum number of cities

int n = 4; // Number of cities (Replace with your input)
int cost[MAX_N][MAX_N] = {
  {0, 10, 15, 20},
  {10, 0, 35, 25},
  {15, 35, 0, 30},
  {20, 25, 30, 0}
}; // Cost matrix (Replace with your input)
int dp[1 << MAX_N][MAX_N]; // Dynamic programming table

int min(int a, int b) {
  return (a < b) ? a : b;
}

// Function to calculate the minimum cost TSP using DP
int tsp(int mask, int pos) {
  if (mask == (1 << n) - 1) {
    return cost[pos][0]; // Return to the starting city
  }
  if (dp[mask][pos] != -1) {
    return dp[mask][pos]; // Already calculated, return stored value
  }
  int ans = INT_MAX;
  for (int next = 0; next < n; next++) {
    if ((mask & (1 << next)) == 0) { // If city 'next' is not visited
      int newCost = cost[pos][next] + tsp(mask | (1 << next), next);
      ans = min(ans, newCost);
    }
  }
  dp[mask][pos] = ans; // Store the calculated value
  return ans;
}

int main() {

  // Initialize DP table with -1 (not calculated)
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = -1;
    }
  }

  int minCost = tsp(1, 0); // Start from city 0 (mask = 1)
  printf("Minimum cost tour: %d\n", minCost);

  return 0;
}
