class Solution {
public:
    int dpCalculate(int amount,vector<int>& coins,int i,int sum,vector<vector<int>>&dp){
        if(sum>amount)
        return 0;
        if(sum==amount)
        return 1;
        if(i==coins.size())
        {
            if(sum==amount)
            return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        int ans=0;
        for(int j=i;j<coins.size();j++){
            ans=ans+dpCalculate(amount,coins,j,sum+coins[j],dp);
        }
        return dp[i][sum]=ans;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return dpCalculate(amount,coins,0,0,dp);
    }
};