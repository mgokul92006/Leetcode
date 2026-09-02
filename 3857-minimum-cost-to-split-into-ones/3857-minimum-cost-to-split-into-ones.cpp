class Solution {
public:
    int dpCalculate(int n){
        if(n==1)
        return 0;
        int ans=INT_MAX;
        ans=min(ans,n-1+dpCalculate(n-1));
        return ans;
    }
    int minCost(int n) {
        return dpCalculate(n);
    }
};