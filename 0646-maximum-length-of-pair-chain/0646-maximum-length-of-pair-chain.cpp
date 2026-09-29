class Solution {
public:
    int dpCalculate(int i,vector<int>&st,vector<int>&en,vector<int>&dp){
        if(i>=st.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=0;
        int ind=upper_bound(st.begin(),st.end(),en[i])-st.begin();
        ans=max(ans,1+dpCalculate(ind,st,en,dp));
        ans=max(ans,dpCalculate(i+1,st,en,dp));
        return dp[i]=ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<int>st,en;
        vector<tuple<int,int>>vec;
        for(int i=0;i<pairs.size();i++){
            vec.push_back({pairs[i][0],pairs[i][1]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            auto [start,end]=vec[i];
            st.push_back(start);
            en.push_back(end);
        }
        vector<int>dp(st.size(),-1);
        return dpCalculate(0,st,en,dp);
    }
};