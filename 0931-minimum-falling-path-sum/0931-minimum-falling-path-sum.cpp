class Solution {
public:
    int res=INT_MAX;
    int dpCalculate(vector<vector<int>>&dp,vector<vector<int>>&matrix,int i,int j){
        if(i>=matrix.size() || j>=matrix[0].size() || j<0)
        return 1e7;
        if(i==matrix[0].size()-1){
            return matrix[i][j];
        }
        if(dp[i][j]!=1e9)
        return dp[i][j];
        int ans=1e7;
        ans=min(ans,dpCalculate(dp,matrix,i+1,j-1));
        ans=min(ans,dpCalculate(dp,matrix,i+1,j));
        ans=min(ans,dpCalculate(dp,matrix,i+1,j+1));
        return dp[i][j]=ans+matrix[i][j];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),1e9));
        for(int i=0;i<matrix[0].size();i++)
            res=min(res,dpCalculate(dp,matrix,0,i));
        return res;
    }
};