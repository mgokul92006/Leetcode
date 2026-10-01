class Solution {
public:
    int dpCalculate(long long n){
        if(n==1)
        return 0;
        int ans=1e9;
        if(n%2==0)
            ans=min(ans,1+dpCalculate(n/2));
        else{
            ans=min(ans,1+dpCalculate(n+1));
            ans=min(ans,1+dpCalculate(n-1));
        }
        return ans;
    }
    int integerReplacement(int n) {
        return dpCalculate(n);
    }
};