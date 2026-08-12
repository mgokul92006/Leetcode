class Solution {
public:
    int MOD=1e9+7;
    int dpCalculate(vector<vector<vector<int>>>&dp,int i,int a,int l,int n){
        if(i>n)
        return 0;
        if(i==n)
        return 1;
        if(dp[i][a][l]!=-1)
        return dp[i][a][l];
        int ans=0;
        if(a==0){
            ans=(ans+dpCalculate(dp,i+1,1,0,n)%MOD)%MOD;
        }
        if(l<2){
            ans=(ans+dpCalculate(dp,i+1,a,l+1,n)%MOD)%MOD;
        }
        ans=(ans+dpCalculate(dp,i+1,a,0,n)%MOD)%MOD;
        return dp[i][a][l]=ans%MOD;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return dpCalculate(dp,0,0,0,n);
    }
};