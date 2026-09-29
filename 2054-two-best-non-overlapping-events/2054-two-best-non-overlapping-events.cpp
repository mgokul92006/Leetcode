class Solution {
public:
    int dpCalculate(int i,int count,vector<int>&st,vector<int>&en,vector<int>&pro,vector<vector<int>>&dp){
        if(i>=st.size())
        return 0;
        if(count>=2)
        return 0;
        if(dp[i][count]!=-1)
        return dp[i][count];
        int ans=0;
        ans=max(ans,pro[i]+dpCalculate(upper_bound(st.begin(),st.end(),en[i])-st.begin(),count+1,st,en,pro,dp));
        ans=max(ans,dpCalculate(i+1,count,st,en,pro,dp));
        return dp[i][count]=ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<tuple<int,int,int>>vec;
        for(int i=0;i<events.size();i++){
            vec.push_back({events[i][0],events[i][1],events[i][2]});
        }
        vector<int>st,en,pro;
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            auto [start,end,profit]=vec[i];
            st.push_back(start);
            en.push_back(end);
            pro.push_back(profit);
        }
        vector<vector<int>>dp(vec.size(),vector<int>(3,-1));
        return dpCalculate(0,0,st,en,pro,dp);
    }
};