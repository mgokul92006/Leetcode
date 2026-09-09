class Solution {
public:
    int dpCalculate(int i,vector<int>&days,vector<int>&costs,vector<int>&dp){
        if(i>=days.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int cost=1e9;
        cost=min(cost,costs[0]+dpCalculate(upper_bound(days.begin()+i,days.end(),days[i])-days.begin(),days,costs,dp));
        cost=min(cost,costs[1]+dpCalculate(upper_bound(days.begin()+i,days.end(),days[i]+6)-days.begin(),days,costs,dp));
        cost=min(cost,costs[2]+dpCalculate(upper_bound(days.begin()+i,days.end(),days[i]+29)-days.begin(),days,costs,dp));
        return dp[i]=cost;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return dpCalculate(0,days,costs,dp);
    }
};