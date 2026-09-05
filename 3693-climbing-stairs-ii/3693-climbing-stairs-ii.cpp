class Solution {
public:
    int dpCalculate(int n, vector<int>& costs,int i,vector<int>&dp){
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=1e9;
        if(i+1<=costs.size())
            ans=min(ans,costs[i]+(i+1-i)*(i+1-i)+dpCalculate(n,costs,i+1,dp));
        if(i+2<=costs.size())
            ans=min(ans,costs[i+1]+(i+2-i)*(i+2-i)+dpCalculate(n,costs,i+2,dp));
        if(i+3<=costs.size())
            ans=min(ans,costs[i+2]+(i+3-i)*(i+3-i)+dpCalculate(n,costs,i+3,dp));
        return dp[i]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n,-1);
        return dpCalculate(n,costs,0,dp);
    }
};