class Solution {
public:
    bool dpCalculate(vector<int>& stones, int i, int prev, map<int, int>& mp,
                     int k,vector<vector<int>>&dp) {
        if (i >= stones.size() || i < 0)
            return 0;
        if (i == stones.size()-1)
            return 1;
        if(dp[i][prev]!=-1)
        return dp[i][prev];
        bool ans = 0;
        if (mp.find(stones[i] + prev + 1) != mp.end() && stones[i]+prev+1!=i)
            ans = ans || dpCalculate(stones, mp[stones[i]+prev+1], prev + 1, mp, k,dp);
        if (mp.find(stones[i] + prev - 1) != mp.end() && i+prev-1!=i)
            ans = ans || dpCalculate(stones, mp[stones[i] + prev - 1], prev - 1, mp, k,dp);
        if (mp.find(prev + stones[i]) != mp.end() && i+prev!=i)
            ans = ans || dpCalculate(stones, mp[stones[i] + prev], prev, mp, k,dp);
        return dp[i][prev]=ans;
    }
    bool canCross(vector<int>& stones) {
        map<int, int> mp;
        int k = stones[stones.size() - 1];
        int j=0;
        for (auto i : stones){
            mp[i]=j;
            j++;
        }
        vector<vector<int>>dp(stones.size(),vector<int>(stones.size(),-1));
        return dpCalculate(stones, 0, 0, mp, k,dp);
    }
};