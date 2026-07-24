class Solution {
public:
    int dpCalculate(vector<int>& nums1, vector<int>& nums2,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=0;
        if(nums1[i]==nums2[j])
        ans=1+dpCalculate(nums1,nums2,i-1,j-1,dp);
        return dp[i][j]=ans;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res=0;
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                res=max(res,dpCalculate(nums1,nums2,i,j,dp));
            }
        }
        return res;
    }
};