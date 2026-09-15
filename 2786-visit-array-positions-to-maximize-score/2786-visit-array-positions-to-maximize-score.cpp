class Solution {
public:
    long long dpCalculate(vector<int>&nums,int x,int i,int prev,vector<vector<long long>>&dp){
        if(i>=nums.size())
        return 0;
        if(dp[i][prev]!=-1)
        return dp[i][prev];
        long long ans=-1e9;
        if(prev==nums[i]%2)
            ans=max(ans,nums[i]+dpCalculate(nums,x,i+1,prev,dp));
        else
            ans=max(ans,nums[i]+dpCalculate(nums,x,i+1,nums[i]%2,dp)-x);
        ans=max(ans,dpCalculate(nums,x,i+1,prev,dp));
        return dp[i][prev]=ans;
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return dpCalculate(nums,x,1,nums[0]%2,dp)+nums[0];
    }
};