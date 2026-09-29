class Solution {
public:
    int dpCalculate(int i,vector<int>& startTime, vector<int>& endTime, vector<int>& profit,vector<int>&dp){
        if(i>=startTime.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=0;
        ans=max(ans,profit[i]+dpCalculate(lower_bound(startTime.begin(),startTime.end(),endTime[i])-startTime.begin(),startTime,endTime,profit,dp));
        ans=max(ans,dpCalculate(i+1,startTime,endTime,profit,dp));
        return dp[i]=ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<tuple<int,int,int>>vec;
        for(int i=0;i<startTime.size();i++){
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            auto [st,en,pr]=vec[i];
            startTime[i]=st;
            endTime[i]=en;
            profit[i]=pr;
        }
        vector<int>dp(vec.size(),-1);
        return dpCalculate(0,startTime,endTime,profit,dp);
    }
};