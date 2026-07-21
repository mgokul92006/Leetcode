class Solution {
public:
    int dpCalculate(string& word1,string& word2,int i, int j,vector<vector<int>>&dp){
        if(i>=word1.size() || j>=word2.size())
        return 0;
        int take=0,nottake=0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(word1[i]==word2[j])
        take=1+dpCalculate(word1,word2,i+1,j+1,dp);
        nottake=max(dpCalculate(word1,word2,i,j+1,dp),dpCalculate(word1,word2,i+1,j,dp));
        return dp[i][j]=max(take,nottake);
    }
    int minDistance(string word1, string word2) {
        int ans=word1.size()+word2.size();
        vector<vector<int>>dp(501,vector<int>(501,-1));
        int c=dpCalculate(word1,word2,0,0,dp);
        return ans-(c+c);
    }
};