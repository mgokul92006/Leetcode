class Solution {
public:
    bool check(long long m,vector<int>&coins,long long k){
        long long final=(1<<coins.size())-1,ans=0;
        for(long long mask=1;mask<=final;mask++){
            long long lcmVal=1;
            for(int i=0;i<coins.size();i++){
                if(mask & (1<<i))
                    lcmVal=lcm(lcmVal,coins[i]);
            }
            if(__builtin_popcount(mask)%2)
                ans=ans+(m/lcmVal);
            else
                ans=ans-(m/lcmVal);
        }
        return ans>=k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l=1,h=1ll*(*min_element(coins.begin(),coins.end()))*k;
        long long ans=0;
        while(l<=h){
            long long m=(h-l)/2+l;
            if(check(m,coins,k)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};