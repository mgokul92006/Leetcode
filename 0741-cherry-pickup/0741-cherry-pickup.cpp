class Solution {
public:
    int dpCalculate(vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>&dp,int i,int j,int l,int k,int n){
        if(i>=n || j>=n || l>=n || k>=n)
        return -1e7;
        if(grid[i][j]==-1 || grid[l][k]==-1)
        return -1e7;
        if(i==n-1 && j==n-1 && l==n-1 && k==n-1)
        return grid[i][j];
        if(dp[i][j][l][k]!=-1)
        return dp[i][j][l][k];
        int ans=-1e7;
        if(i==l && j==k)
        ans=max(ans,dpCalculate(grid,dp,i+1,j,l,k+1,n)+grid[i][j]);
        else
        ans=max(ans,dpCalculate(grid,dp,i+1,j,l,k+1,n)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
        ans=max(ans,dpCalculate(grid,dp,i,j+1,l+1,k,n)+grid[i][j]);
        else
        ans=max(ans,dpCalculate(grid,dp,i,j+1,l+1,k,n)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
        ans=max(ans,dpCalculate(grid,dp,i,j+1,l,k+1,n)+grid[i][j]);
        else
        ans=max(ans,dpCalculate(grid,dp,i,j+1,l,k+1,n)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
        ans=max(ans,dpCalculate(grid,dp,i+1,j,l+1,k,n)+grid[i][j]);
        else
        ans=max(ans,dpCalculate(grid,dp,i+1,j,l+1,k,n)+grid[i][j]+grid[l][k]);
        return dp[i][j][l][k]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int d= dpCalculate(grid,dp,0,0,0,0,n);
        if(d<=0)
        return 0;
        return d;
    }
};