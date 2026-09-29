class Solution {
public:
    long long dpCalculate(int i,vector<int>&st,vector<int>&en,vector<int>&pro,vector<long long>&dp){
        if(i>=st.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        long long ans=0;
        ans=max(ans,en[i]-st[i]+pro[i]+dpCalculate(lower_bound(st.begin(),st.end(),en[i])-st.begin(),st,en,pro,dp));
        ans=max(ans,dpCalculate(i+1,st,en,pro,dp));
        return dp[i]=ans;
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<tuple<int,int,int>>vec;
        vector<int>st,en,pro;
        for(int i=0;i<rides.size();i++){
            st.push_back(rides[i][0]);
            en.push_back(rides[i][1]);
            pro.push_back(rides[i][2]);
            vec.push_back({rides[i][0],rides[i][1],rides[i][2]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            auto [start,end,profit]=vec[i];
            st[i]=start;
            en[i]=end;
            pro[i]=profit;
        }
        vector<long long>dp(st.size(),-1);
        return dpCalculate(0,st,en,pro,dp);
    }
};