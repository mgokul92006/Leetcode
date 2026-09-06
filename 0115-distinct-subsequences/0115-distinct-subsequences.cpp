class Solution {
public:
    int dpCalculate(int i,int j,string& s,string& t,vector<vector<int>>&dp){
        if(j==t.size())
        return 1;
        if(i==s.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(s[i]==t[j])
            ans=ans+dpCalculate(i+1,j+1,s,t,dp);
        ans=ans+dpCalculate(i+1,j,s,t,dp);
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return dpCalculate(0,0,s,t,dp);
    }
};