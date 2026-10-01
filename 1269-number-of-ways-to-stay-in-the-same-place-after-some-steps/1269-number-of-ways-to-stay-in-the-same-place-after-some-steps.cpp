class Solution {
public:
    int mod=1e9+7;
    int dpCalculate(int steps,int arrLen,int i,vector<vector<int>>&dp){
        if(steps==0 && i==0)
        return 1;
        if(steps==0 || i>=arrLen || i<0 || steps<0)
        return 0;
        if(dp[i][steps]!=-1)
        return dp[i][steps];
        int ans=0;
        ans=(ans+dpCalculate(steps-1,arrLen,i+1,dp))%mod;
        ans=(ans+dpCalculate(steps-1,arrLen,i-1,dp))%mod;
        ans=(ans+(dpCalculate(steps-1,arrLen,i,dp)))%mod;
        return dp[i][steps]=ans%mod;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>>dp(min(arrLen,501),vector<int>(501,-1));
        return dpCalculate(steps,arrLen,0,dp);
    }
};