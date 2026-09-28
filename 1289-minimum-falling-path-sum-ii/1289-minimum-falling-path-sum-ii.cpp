class Solution {
public:
    int dpCalculate(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp){
        if(i==grid.size())
        return 0;
        if(dp[i][j]!=INT_MAX)
        return dp[i][j];
        int ans=1e7;
        for(int z=0;z<grid[0].size();z++){
            if(z==j)
            continue;
            ans=min(ans,grid[i][z]+dpCalculate(grid,i+1,z,dp));
        }
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int mini=1e7;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        for(int i=0;i<grid[0].size();i++)
        mini=min(mini,dpCalculate(grid,0,i,dp));
        if(mini==1e7)
        return grid[0][0];
        return mini;
    }
};