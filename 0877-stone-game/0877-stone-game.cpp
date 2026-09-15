class Solution {
public:
    int recur(vector<int>&piles,int l,int r,vector<vector<int>>&dp){
        if(l>r)
        return 0;
        if(dp[l][r]!=-1)
        return dp[l][r];
        int left=0,right=0;
        left=max(left,piles[l]-(recur(piles,l+1,r,dp)));
        right=max(right,piles[r]-recur(piles,l,r-1,dp));
        return dp[l][r]=left+right>=0;
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        return recur(piles,0,piles.size()-1,dp);
    }
};