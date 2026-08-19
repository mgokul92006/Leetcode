class Solution {
public:
    int dpCalculate(vector<vector<int>>&grid,int i,int j,int l,int k,vector<vector<vector<vector<int>>>>&dp){
        if(i<0 || j<0 || l<0 || k<0)
        return -1e7;
        if(i>=grid.size() || j>=grid[0].size() || l>=grid.size() || k>=grid[0].size())
        return -1e7;
        if(i==grid.size()-1 && l==grid.size()-1)
        {
            if(i==l && j==k)
            return grid[i][j];
            return grid[i][j]+grid[l][k];
        }
        if(dp[i][j][l][k]!=-1)
        return dp[i][j][l][k];
        int ans=-1e7;
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j-1,l+1,k-1,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j-1,l+1,k-1,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j,l+1,k,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j,l+1,k,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j+1,l+1,k+1,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j+1,l+1,k+1,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j-1,l+1,k,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j-1,l+1,k,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j-1,l+1,k+1,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j-1,l+1,k+1,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j,l+1,k-1,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j,l+1,k-1,dp)+grid[i][j]+grid[l][k]);
         if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j,l+1,k+1,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j,l+1,k+1,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j+1,l+1,k-1,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j+1,l+1,k-1,dp)+grid[i][j]+grid[l][k]);
        if(i==l && j==k)
            ans=max(ans,dpCalculate(grid,i+1,j+1,l+1,k,dp)+grid[i][j]);
        else
            ans=max(ans,dpCalculate(grid,i+1,j+1,l+1,k,dp)+grid[i][j]+grid[l][k]);
        return dp[i][j][l][k]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<vector<int>>>>dp(grid.size(),vector<vector<vector<int>>>(grid[0].size(),vector<vector<int>>(100,vector<int>(100,-1))));
        return dpCalculate(grid,0,0,0,grid[0].size()-1,dp);
    }
};