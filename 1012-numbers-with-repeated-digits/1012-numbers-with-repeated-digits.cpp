class Solution {
public:
    int dp[11][2][1024][2][2];
    int dpCalculate(string& a,int i,int tight,int mask,int rep,int lz){
        if(a.size()==i)
        return rep;
        if(dp[i][tight][mask][rep][lz]!=-1)
        return dp[i][tight][mask][rep][lz];
        int ans=0;
        int ub=(tight==1)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(lz && j==0)
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),mask,rep,lz);
            else{
                int in=1 & (mask>>j);
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),mask | 1<<j,rep || in,0);
            }
        }
        return dp[i][tight][mask][rep][lz]=ans;
    }
    int numDupDigitsAtMostN(int n) {
        string a=to_string(n);
        memset(dp,-1,sizeof(dp));
        return dpCalculate(a,0,1,0,0,1);
    }
};