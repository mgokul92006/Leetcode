class Solution {
public:
    int dpCalculate(vector<int>&nums,int target,int sum,vector<int>&dp){
        if(sum>target)
        return 0;
        if(sum==target)
        return 1;
        if(dp[sum]!=-1)
        return dp[sum];
        int ans=0;
        for(int j=0;j<nums.size();j++){
            if(sum+nums[j]<=target)
                ans=ans+dpCalculate(nums,target,sum+nums[j],dp);
        }
        return dp[sum]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+2,-1);
        return dpCalculate(nums,target,0,dp);
    }
};