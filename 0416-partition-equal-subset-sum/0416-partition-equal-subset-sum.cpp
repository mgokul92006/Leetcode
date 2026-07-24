class Solution {
public:
    int dpCalculate(vector<int>& nums,int i,int tar,int sum,vector<vector<unsigned long long>>&dp){
        if(i==nums.size()){
        if(sum==tar)
        return 1;
        return 0;
        }
        if(sum>tar)
        return 0;
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        unsigned long long take=0,nottake=0;
        take=dpCalculate(nums,i+1,tar,sum+nums[i],dp);
        nottake=dpCalculate(nums,i+1,tar,sum,dp);
        return dp[i][sum]=take+nottake;
    }
    bool canPartition(vector<int>& nums) {
        int tar=accumulate(nums.begin(),nums.end(),0);
        if(tar%2!=0)
        return 0;
        tar=tar/2;
        vector<vector<unsigned long long>>dp(nums.size(),vector<unsigned long long>(tar+1,-1));
        return dpCalculate(nums,0,tar,0,dp);
    }
};