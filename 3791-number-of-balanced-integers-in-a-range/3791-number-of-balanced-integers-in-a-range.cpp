class Solution {
public:
    long long dp[16][2][2][200][16];
    long long dpCalculate(string& a,int i,int tight,int lz,long long sum,int dig){
        if(a.size()==i){
            if(sum==0 && dig>=2)
            return 1;
            return 0;
        }
        if(dp[i][tight][lz][sum+100][dig]!=-1)
        return dp[i][tight][lz][sum+100][dig];
        long long ans=0;
        int ub=(tight)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            int c=0,c1=0;
            if(!(lz && (j==0))){
            if(dig%2==0)
                c=j;
            else
                c=-j;
            c1=c1+1;
            }
            ans=ans+dpCalculate(a,i+1,(tight && ub==j),(lz && j==0),sum+c,dig+c1);
        }
        return dp[i][tight][lz][sum+100][dig]=ans;
    }
    long long countBalanced(long long low, long long high) {
        string a=to_string(high),b=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        long long ans1=dpCalculate(a,0,1,1,0,0);
        memset(dp,-1,sizeof(dp));
        long long ans2=dpCalculate(b,0,1,1,0,0);
        return ans1-ans2;
    }
};