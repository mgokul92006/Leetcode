class Solution {
public:
    int dpCalculate(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
        if(s1.size()<=i || s2.size()<=j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0,nontake=0;
        if(s1[i]==s2[j])
        take=1+dpCalculate(s1,s2,i+1,j+1,dp);
        nontake=max(dpCalculate(s1,s2,i,j+1,dp),dpCalculate(s1,s2,i+1,j,dp));
        return dp[i][j]=max(take,nontake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        return dpCalculate(text1,text2,0,0,dp);
    }
};