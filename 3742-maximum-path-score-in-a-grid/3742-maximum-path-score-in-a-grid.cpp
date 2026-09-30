class Solution {
public:
    int dpCalculate(vector<vector<int>>&grid,int i, int j, int k,vector<vector<vector<int>>>&dp){
        if(grid.size()==i || grid[0].size()==j)
        return -1e7;
        if(k<0)
        return -1e7;
        if(grid.size()-1==i && grid[0].size()-1==j){
            if(grid[i][j]==1 || grid[i][j]==2){
                if(k-1<0)
                return -1e7;
            }
            return grid[i][j];
        }
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        int ans=-1e7;
        if(grid[i][j]==1 || grid[i][j]==2){
            ans=max(ans,grid[i][j]+dpCalculate(grid,i+1,j,k-1,dp));
            ans=max(ans,grid[i][j]+dpCalculate(grid,i,j+1,k-1,dp));
        }
        else{
            ans=max(ans,dpCalculate(grid,i+1,j,k,dp));
            ans=max(ans,dpCalculate(grid,i,j+1,k,dp));
        }
        return dp[i][j][k]=ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        int ans=dpCalculate(grid,0,0,k,dp);
        if(ans<0)
        return -1;
        return ans;
    }
};