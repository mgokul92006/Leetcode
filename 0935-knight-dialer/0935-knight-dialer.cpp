class Solution {
public:
    int mod=1e9+7;
    int dpCalculate(int i,int st,vector<vector<int>>&b,vector<vector<int>>&dp){
        if(st==0)
        return 1;
        if(dp[i][st]!=-1)
        return dp[i][st];
        long long ans=0;
        for(auto j:b[i]){
            ans=(ans+(dpCalculate(j,st-1,b,dp)%mod))%mod;
        }
        return dp[i][st]=ans;
    }
    int knightDialer(int n) {
        int c=0;
        vector<vector<int>>dp(10,vector<int>(n,-1));
        vector<vector<int>>b(10);
        b[0]={4,6};
        b[1]={8,6};
        b[2]={7,9};
        b[3]={4,8};
        b[4]={3,9,0};
        b[6]={1,7,0};
        b[7]={2,6};
        b[8]={1,3};
        b[9]={2,4};
        for(int i=0;i<=9;i++){
            c=(c+(dpCalculate(i,n-1,b,dp))%mod)%mod;
        }
        return c;
    }
};