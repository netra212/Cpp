#include <iostream>
using namespace std;

/**
 * Solving any dp problems follows 3 steps. 
 * 1. Recursive ways. 
 * 2. Top down. 
 * 3. Bottom up. (starting solving problems with for loop)
 * 4. Space Optimization. 
 * 
 */

int fibonacci(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = fibonacci(n, dp) + fibonacci(n-1, dp);
}

int fib(int n){
    vector<int> dp(n+1, -1);
    fibonacci(n,dp);
}

int main(){
    // 
}




