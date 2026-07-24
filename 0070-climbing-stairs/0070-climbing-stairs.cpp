class Solution {
public:
    int dpCalculate(int i,int n){
        if(i>n)
        return 0;
        if(i==n || i==n-1)
        return 1;
        int take=dpCalculate(i+1,n);
        int nottake=dpCalculate(i+2,n);
        return take+nottake;
    }
    int climbStairs(int n) {
        //return dpCalculate(0,n);
        vector<int>dp(n+1,0);
        dp[n]=1;
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1]+dp[i+2];
        }
        return dp[0];
    }
};