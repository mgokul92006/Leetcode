class Solution {
public:
    int dpCalculate(vector<int>&ages,vector<int>&scores,int i,int prev,vector<vector<int>>&dp){
        if(ages.size()==i)
        return 0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        int ans=0;
        if(prev==-1)
            ans=max(ans,scores[i]+dpCalculate(ages,scores,i+1,i,dp));
        if(prev!=-1 && ages[i]==ages[prev])
            ans=max(ans,scores[i]+dpCalculate(ages,scores,i+1,i,dp));
        if(prev!=-1 && ages[prev]<ages[i] && scores[i]>=scores[prev])
            ans=max(ans,scores[i]+dpCalculate(ages,scores,i+1,i,dp));
        ans=max(ans,dpCalculate(ages,scores,i+1,prev,dp));
        return dp[i][prev+1]=ans;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<tuple<int,int>>vec;
        for(int i=0;i<ages.size();i++){
            vec.push_back({ages[i],scores[i]});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            auto [ag,sc]=vec[i];
            ages[i]=ag;
            scores[i]=sc;
        }
        vector<vector<int>>dp(ages.size(),vector<int>(ages.size()+1,-1));
        return dpCalculate(ages,scores,0,-1,dp);
    }
};