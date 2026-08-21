class Solution {
public:
    int dpCalculate(int i,vector<int>&arr,int d,vector<int>&dp){
        if(dp[i]!=-1)
        return dp[i];
        int left=0,right=0,c1=1,c2=1;
        for(int j=1;j<=d;j++){
            if(i-j>=0 && arr[i-j]<arr[i] && c1)
                left=max(left,dpCalculate(i-j,arr,d,dp));
            else
                c1=0;
            if(i+j<arr.size() && arr[i+j]<arr[i] && c2)
                right=max(right,dpCalculate(i+j,arr,d,dp));
            else
                c2=0;
        }
        return dp[i]=1+max(left,right);
    }
    int maxJumps(vector<int>& arr, int d) {
        int maxi=0;
        vector<int>dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,dpCalculate(i,arr,d,dp));
        }
        return maxi;
    }
};