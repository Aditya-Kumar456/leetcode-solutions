class Solution {
public:
    
    // int solve(int n, vector<int>&dp){
    //     if(n <= 1){
    //         return n;
    //     }

    //     if(dp[n] != -1){
    //         return dp[n];
    //     }

    //     dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    //     return dp[n];
    // }

    // int solve1(int n, vector<int>&dp){
    //     if(n <= 1){
    //         return n;
    //     }

    //     dp[0] = 0;
    //     dp[1] = 1;

    //     for(int i = 2; i <= n; i++){
    //     dp[i] = dp[i - 1] + dp[i - 2];
    //     }

    //     return dp[n];
    // }

    int fib(int n) {
        // vector<int>dp(n + 1, -1);
        // return solve1(n, dp);

        if(n <= 1){
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;
        for(int i = 2; i <= n; i++){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};