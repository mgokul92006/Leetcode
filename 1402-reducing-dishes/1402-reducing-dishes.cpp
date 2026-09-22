class Solution {
public:
    int dpCalculate(vector<int>& satisfaction,int i,int time,vector<vector<int>>&dp){
        if(i>=satisfaction.size())
        return 0;
        if(dp[i][time]!=-1)
        return dp[i][time];
        int ans=0;
        ans=max(ans,satisfaction[i]*time+dpCalculate(satisfaction,i+1,time+1,dp));
        ans=max(ans,dpCalculate(satisfaction,i+1,time,dp));
        return dp[i][time]=ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        return dpCalculate(satisfaction,0,1,dp);
    }
};