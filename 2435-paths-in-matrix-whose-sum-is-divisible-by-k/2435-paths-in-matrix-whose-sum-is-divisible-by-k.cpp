class Solution {
public:
    int MOD=1e9+7;
    int dpCalculate(vector<vector<int>>&grid,int i,int j,int k,int sum,vector<vector<vector<int>>>&dp){
        if(i>=grid.size() || j>=grid[0].size())
        return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return (sum+grid[i][j])%k==0;
        }
        if(dp[i][j][sum]!=-1)
        return dp[i][j][sum];
        return dp[i][j][sum]=((dpCalculate(grid,i+1,j,k,(sum+grid[i][j])%k,dp))%MOD+(dpCalculate(grid,i,j+1,k,(sum+grid[i][j])%k,dp))%MOD)%MOD;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,-1)));
        return dpCalculate(grid,0,0,k,0,dp);
    }
};