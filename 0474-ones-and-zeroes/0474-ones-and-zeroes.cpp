class Solution {
public:
    int dpCalculate(int i,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
        if(i>=strs.size())
        return 0;
        if(dp[i][m][n]!=-1)
        return dp[i][m][n];
        int c1=0,c2=0,ans=0;
        for(int j=0;j<strs[i].size();j++){
            if(strs[i][j]=='1')
            c1++;
            else
            c2++;
        }
        if(n-c1>=0 && m-c2>=0)
            ans=max(ans,1+dpCalculate(i+1,m-c2,n-c1,strs,dp));
        ans=max(ans,dpCalculate(i+1,m,n,strs,dp));
        return dp[i][m][n]=ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return dpCalculate(0,m,n,strs,dp);
    }
};