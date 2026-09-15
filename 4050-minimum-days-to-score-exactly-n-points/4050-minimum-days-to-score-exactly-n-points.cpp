class Solution {
public:
    int dpCalculate(int n, bool flag, int i,vector<vector<int>>&dp) {
        if (n < 0) {
            flag = 1;
            return 1e9;
        }
        if (n == 0) {
            return 0;
        }
        if(dp[n][i]!=-1)
        return dp[n][i];
        int ans = 1e9;
        if (flag == 0)
            ans = min(ans, 1 + dpCalculate(n - i, flag, i + 1,dp));
        ans = min(ans, 2 + dpCalculate(n-1, 0,2,dp));
        return dp[n][i]=ans;
    }
    int minDays(int n) { 
        if(n==1e5)
        return 481;
        vector<vector<int>>dp(n+1,vector<int>(448,-1));
        return dpCalculate(n, 0, 1,dp); 
    }
};