class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,0));
        for(int i=1;i<=amount;i++)
            dp[0][i]=1e9;
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
            }
        }
        return dp[coins.size()][amount]==1e9?-1:dp[coins.size()][amount];
    }
};