class Solution {
public:
    int dpCalculate(int i,int count,int hold,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i==prices.size())
        return 0;
        if(count==0)
        return 0;
        if(dp[i][count][hold]!=-1)
        return dp[i][count][hold];
        int ans=0;
        if(hold==0){
            ans=dpCalculate(i+1,count-1,1,prices,dp)-prices[i];
        }
        else
            ans=dpCalculate(i+1,count,0,prices,dp)+prices[i];
        return dp[i][count][hold]=max(ans,dpCalculate(i+1,count,hold,prices,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(4,vector<int>(2,-1)));
        return dpCalculate(0,3,0,prices,dp);
    }
};