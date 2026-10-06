class Solution {
public:
    long long dp[16][2][2][12];
    long long dpCalculate(string& n,int& k,int i,int tight,int lz,int prev){
        if(n.size()==i)
        return lz?0:1;
        if(dp[i][tight][lz][prev]!=-1)
        return dp[i][tight][lz][prev];
        long long ans=0;
        long long ub=(tight==1)?n[i]-'0':9;
        for(long long j=0;j<=ub;j++){
            if(prev!=11 && abs(j-prev)>k)
            continue;
            if(lz && j==0){
                ans=ans+dpCalculate(n,k,i+1,(tight && j==ub),(lz && j==0),11);
            }
            else {
                ans=ans+dpCalculate(n,k,i+1,(tight && j==ub),0,j);
            }
        }
        return dp[i][tight][lz][prev]=ans;
    }
    long long goodIntegers(long long l, long long r, int k) {
        string s1=to_string(r),s2=to_string(l-1);
        memset(dp,-1,sizeof(dp));
        long long a=dpCalculate(s1,k,0,1,1,11);
        memset(dp,-1,sizeof(dp));
        long long b=dpCalculate(s2,k,0,1,1,11);
        return a-b;
    }
};