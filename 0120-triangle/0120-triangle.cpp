class Solution {
public:
    int dpCalculate(vector<vector<int>>&triangle,int i,int j,vector<vector<int>>&dp){
        if(i==triangle.size())
        return 0;
        if(j==triangle[i].size())
        return 0;
        if(dp[i][j]!=1e7)
        return dp[i][j];
        int take=1e7,nottake=1e7;
        take=triangle[i][j]+dpCalculate(triangle,i+1,j,dp);
        nottake=triangle[i][j]+dpCalculate(triangle,i+1,j+1,dp);
        return dp[i][j]=min(take,nottake);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(202,vector<int>(202,1e7));
        return dpCalculate(triangle,0,0,dp);
    }
};