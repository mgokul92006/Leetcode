class Solution {
public:
    int mod=1e9+7;
    long long dpCalculate(int n,int k,int target,vector<vector<long long>>&dp){
        if(n==0 && target==0)
        return 1;
        if(n<0 || target<0)
        return 0;
        if(dp[n][target]!=-1)
        return dp[n][target];
        long long ans=0;
        for(int i=1;i<=k;i++){
            ans=(ans+(dpCalculate(n-1,k,target-i,dp)%mod))%mod;
        }
        return dp[n][target]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>>dp(35,vector<long long>(1004,-1));
        return dpCalculate(n,k,target,dp)%mod;
    }
};