class Solution {
public:
    int dpCalculate(string& w1,string& w2,int i,int j,vector<vector<int>>&dp){
        if(i<0 && j<0)
        return 0;
        if(i<0 && j>=0)
        return j+1;
        if(i>=0 && j<0)
        return i+1;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=1e7,nottake=1e7;
        if(w1[i]==w2[j])
        take=dpCalculate(w1,w2,i-1,j-1,dp);
        else
        nottake=1+min({dpCalculate(w1,w2,i-1,j,dp),dpCalculate(w1,w2,i-1,j-1,dp),dpCalculate(w1,w2,i,j-1,dp)});
        return dp[i][j]=min(take,nottake);
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return dpCalculate(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};