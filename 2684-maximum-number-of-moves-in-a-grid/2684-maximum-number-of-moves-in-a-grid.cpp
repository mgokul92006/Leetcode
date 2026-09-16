class Solution {
public:
    int dpCalculate(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(i-1>=0 && j+1<grid[0].size() && grid[i][j]<grid[i-1][j+1])
        ans=max(ans,1+dpCalculate(grid,i-1,j+1,dp));
        if(j+1<grid[0].size() && grid[i][j]<grid[i][j+1])
        ans=max(ans,1+dpCalculate(grid,i,j+1,dp));
        if(i+1<grid.size() && j+1<grid[0].size() && grid[i][j]<grid[i+1][j+1])
        ans=max(ans,1+dpCalculate(grid,i+1,j+1,dp));
        return dp[i][j]=ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int c=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++)
            c=max(c,dpCalculate(grid,i,0,dp));
        return c;
    }
};