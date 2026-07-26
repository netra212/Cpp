#include <iostream>
using namespace std;

// Q1. Find the number of ways that anyone can climb trees.
int climbingTrees(int n, vector<int> &dp){

    // base case. 
    if (n <= 2) {
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] = climbingTrees(n-1, dp) + climbingTrees(n-2, dp);
}

int climb(int n){
    vector<int> dp(n+1, -1);

    // Bottom up: or Tabulation Method, Just using for loop. 
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    climbingTrees(5, dp);
}

// Q2. Frog Jumps steps. (Count number of hops).
// A frog jumps either 1, 2, or 3 steps to reach the top of a staircase with n steps. Calculate the number of distinct ways the frog can reach the nth step.
int countNumberHops(int n){

}

// Q3. Minimum Cost Climbing stairs problems. 
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or twp steps. 
// You can either start from the step with index 0, or the step with index 1. 
// Return the minimum cost to reach the top of the floor. 
int minCostClimbingStairs(vector<int> &cost){
    // minCost(n) = min(cost(n-1)+minCost(n-1), cost(n-2)+minCost(n-2))
}


