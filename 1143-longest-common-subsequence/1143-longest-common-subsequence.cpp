class Solution {
public:
    int dpCalculate(string& t1,string& t2,int i,int j,vector<vector<int>>&dp){
        if(i==t1.size() || j==t2.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0,nottake=0;
        if(t1[i]==t2[j])
        take=1+dpCalculate(t1,t2,i+1,j+1,dp);
        nottake=max(dpCalculate(t1,t2,i,j+1,dp),dpCalculate(t1,t2,i+1,j,dp));
        return dp[i][j]=max(take,nottake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        //return dpCalculate(text1,text2,0,0,dp);
        for(int i=text1.size()-1;i>=0;i--){
            for(int j=text2.size()-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};