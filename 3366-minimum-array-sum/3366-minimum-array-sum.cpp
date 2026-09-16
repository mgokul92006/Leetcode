class Solution {
public:
    int dpCalculate(vector<int>& nums, int k, int op1, int op2,int i,vector<vector<vector<int>>>&dp){
        if(i>=nums.size())
        return 0;
        if(dp[i][op1][op2]!=-1)
        return dp[i][op1][op2];
        int ans=1e9;
        int p=0;
        if(nums[i]%2!=0)
            p=1;
        if(op1>0 && op2>0){
            if(p+(nums[i]/2)-k>=0){
                ans=min(ans,p+(nums[i]/2)-k+dpCalculate(nums,k,op1-1,op2-1,i+1,dp));
            }
            if(nums[i]>=k){
                ans=min(ans,(nums[i]-k)/2+(nums[i]-k)%2+dpCalculate(nums,k,op1-1,op2-1,i+1,dp));
            }
        }
        if(op1>0){
            ans=min(ans,nums[i]/2+p+dpCalculate(nums,k,op1-1,op2,i+1,dp));
        }
        if(op2>0 && nums[i]>=k)
            ans=min(ans,nums[i]-k+dpCalculate(nums,k,op1,op2-1,i+1,dp));
        ans=min(ans,nums[i]+dpCalculate(nums,k,op1,op2,i+1,dp));
        return dp[i][op1][op2]=ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return dpCalculate(nums,k,op1,op2,0,dp);
    }
};