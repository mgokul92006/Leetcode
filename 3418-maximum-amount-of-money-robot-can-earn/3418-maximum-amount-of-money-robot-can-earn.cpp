class Solution {
public:
    int dpCalculate(vector<vector<int>>& coins,int i,int j,int c,vector<vector<vector<int>>>&dp){
        if(i==coins.size() || j==coins[0].size())
        return -1e9;
        if(i==coins.size()-1 && j==coins[0].size()-1){
            if(c>0 && coins[i][j]<0)
            return 0;
            else
            return coins[i][j];
        }
        if(c<0)
        return -1e9;
        if(dp[i][j][c]!=INT_MIN)
        return dp[i][j][c];
        int ans=INT_MIN;
        if(coins[i][j]<0){
            if(c>0){
            ans=max(ans,dpCalculate(coins,i+1,j,c-1,dp));
            ans=max(ans,dpCalculate(coins,i,j+1,c-1,dp));
            }
            ans=max(ans,coins[i][j]+dpCalculate(coins,i+1,j,c,dp));
            ans=max(ans,coins[i][j]+dpCalculate(coins,i,j+1,c,dp));
        }
        if(coins[i][j]>=0){
            ans=max(ans,coins[i][j]+dpCalculate(coins,i+1,j,c,dp));
            ans=max(ans,coins[i][j]+dpCalculate(coins,i,j+1,c,dp));
        }
        return dp[i][j][c]=ans;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        vector<vector<vector<int>>>dp(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,INT_MIN)));
        return dpCalculate(coins,0,0,2,dp);
    }
};