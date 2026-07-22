class Solution {
public:
    int dpCalculate(vector<vector<int>>&dp,int i,int j,vector<int>&nums1,vector<int>&nums2){
        if(i>=nums1.size() || j>=nums2.size())
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int take=0,nottake=0;
        if(nums1[i]==nums2[j])
        take=1+dpCalculate(dp,i+1,j+1,nums1,nums2);
        nottake=max(dpCalculate(dp,i,j+1,nums1,nums2),dpCalculate(dp,i+1,j,nums1,nums2));
        return dp[i][j]=max(take,nottake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(501,vector<int>(501,-1));
        return dpCalculate(dp,0,0,nums1,nums2);
    }
};