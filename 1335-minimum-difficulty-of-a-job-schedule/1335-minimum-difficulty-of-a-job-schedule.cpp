class Solution {
public:
    int dpCalculate(vector<int>&job,int d,int i,vector<vector<int>>&dp){
        if(i==job.size() && d==0)
        return 0;
        if(i>=job.size() && d!=0)
        return 1e9;
        if(d<0)
        return 1e9;
        if(dp[i][d]!=-1)
        return dp[i][d];
        int ans=1e9;
        int maxi=job[i];
        for(int j=i;j<job.size();j++){
            maxi=max(maxi,job[j]);
            ans=min(ans,maxi+dpCalculate(job,d-1,j+1,dp));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>>dp(jobDifficulty.size(),vector<int>(d+1,-1));
        int ans=dpCalculate(jobDifficulty,d,0,dp);
        if(ans>=1e9)
        return -1;
        return ans;
    }
};