class Solution {
public:
    int dpCalculate(string& s,string& s1,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size() || j>=s1.size()){
            return 0;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0,nottake=0;
        if(s[i]==s1[j])
        take=1+dpCalculate(s,s1,i+1,j+1,dp);
        nottake=max(dpCalculate(s,s1,i+1,j,dp),dpCalculate(s,s1,i,j+1,dp));
        return dp[i][j]=max(take,nottake);
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        reverse(s1.begin(),s1.end());
        return dpCalculate(s,s1,0,0,dp);
    }
};