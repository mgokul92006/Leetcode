class Solution {
public:
    bool check(long long m,int n,int a,int b){
        long long k=0;
        k=(m/a)+(m/b)-(m/lcm(a,b));
        return k>=n;
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long l=1,h=1ll*min(a,b)*n;
        long long ans=0;
        int mod=1e9+7;
        while(l<=h){
            long long m=(h-l)/2+l;
            if(check(m,n,a,b)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans%mod;
    }
};