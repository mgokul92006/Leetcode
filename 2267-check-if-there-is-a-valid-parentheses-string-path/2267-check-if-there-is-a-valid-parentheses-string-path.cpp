class Solution {
public:
    int dpCalculate(vector<vector<char>>& grid, int i, int j, int balance,vector<vector<vector<int>>>&dp) {
        if(i>=grid.size() || j>=grid[0].size())
        return 0;
        if(balance<0)
        return 0;
        if(balance>grid.size())
        return 0;
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {
            if(grid[i][j]!='(' && balance-1==0)
            return 1;
            return 0;
        }
        if(dp[i][j][balance]!=-1)
        return dp[i][j][balance];
        bool ans = false;
        if (i + 1 < grid.size() && grid[i][j] == '(')
            ans = ans || dpCalculate(grid, i + 1, j, balance + 1,dp);
        if (i + 1 < grid.size() && grid[i][j] == ')')
            ans = ans || dpCalculate(grid, i + 1, j, balance - 1,dp);
        if (j + 1 < grid[0].size() && grid[i][j] == '(')
            ans = ans || dpCalculate(grid, i , j+1, balance + 1,dp);
        if (j + 1 < grid[0].size() && grid[i][j] == ')')
            ans = ans || dpCalculate(grid, i , j+1, balance - 1,dp);
        return dp[i][j][balance]=ans;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=(grid.size()+grid[0].size());
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(n,-1)));
        return dpCalculate(grid, 0, 0, 0,dp);
    }
};