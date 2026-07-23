class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int s1=(sum+abs(target));
        if(s1%2!=0)
        return 0;
        s1=s1/2;
        vector<vector<int>>dp(nums.size()+1,vector<int>(s1+1,0));
        for(int i=0;i<=nums.size();i++)
            dp[i][0]=1;
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=s1;j++){
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][s1];
    }
};