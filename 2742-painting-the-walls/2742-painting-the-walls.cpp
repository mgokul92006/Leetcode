class Solution {
public:
    int dpCalculate(vector<int>& cost, vector<int>& time,int i,int c,vector<vector<int>>&dp){
        if(i>=cost.size() && c>=cost.size())
        return 0;
        if(i>=cost.size())
        return 1e9;
        if(c>=cost.size())
        return 0;
        if(dp[i][c]!=-1)
        return dp[i][c];
        int ans=1e9;
        ans=min(ans,cost[i]+dpCalculate(cost,time,i+1,c+time[i]+1,dp));
        ans=min(ans,dpCalculate(cost,time,i+1,c,dp));
        return dp[i][c]=ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>>dp(cost.size(),vector<int>(cost.size()+1,-1));
        return dpCalculate(cost,time,0,0,dp);
    }
};