class Solution {
public:
    bool dpCalculate(int i,int j,string& s,string& p,vector<vector<int>>&dp){
        if(i==s.size() && j==p.size())
        return 1;
        if(j>=p.size() && i<s.size())
        return 0;
        if(j<p.size() && i>=s.size()){
            for(int z=j;z<p.size();z++){
                if(p[z]!='*')
                return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1)
        return dp[i][j];
        bool ans=0;
        if(s[i]==p[j] || p[j]=='?')
            ans=ans + dpCalculate(i+1,j+1,s,p,dp);
        if(p[j]=='*'){
            ans=ans+dpCalculate(i+1,j,s,p,dp);
            ans=ans+dpCalculate(i,j+1,s,p,dp);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size(),-1));
        return dpCalculate(0,0,s,p,dp);
    }
};