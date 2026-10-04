class Solution {
public:
    int mod=1e9+7;
    int dpCalculate(int i,int j,int m,int n,int maxi,vector<vector<vector<int>>>&dp){
        if((i>=m || j>=n || i<0 || j<0) && maxi>=0)
        return 1;
        if(i>=m || j>=n || i<0 || j<0 || maxi<0)
        return 0;
        if(dp[i][j][maxi]!=-1)
        return dp[i][j][maxi];
        int ans=0;
        ans=(ans+dpCalculate(i+1,j,m,n,maxi-1,dp))%mod;
        ans=(ans+dpCalculate(i-1,j,m,n,maxi-1,dp))%mod;
        ans=(ans+dpCalculate(i,j+1,m,n,maxi-1,dp))%mod;
        ans=(ans+dpCalculate(i,j-1,m,n,maxi-1,dp))%mod;
        return dp[i][j][maxi]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return dpCalculate(startRow,startColumn,m,n,maxMove,dp);
    }
};