class Solution {
public:
    int dp[10][2][2][2][1023];
    int dpCalculate(string& a,int n,int i,int tight,int lz,int rep,int mask){
        if(a.size()==i)
            return rep>0?0:1;
        if(dp[i][tight][lz][rep][mask]!=-1)
        return dp[i][tight][lz][rep][mask];
        int ans=0;
        int ub=(tight==1)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(j==0 && lz)
                ans=ans+dpCalculate(a,n,i+1,tight && j==ub,lz,rep,mask);
            else{
                int in=1 & mask>>j;
                ans=ans+dpCalculate(a,n,i+1,tight && j==ub,lz && j==0,rep || in,mask | 1<<j);
            }
        }
        return dp[i][tight][lz][rep][mask]=ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        string ans="";
        for(int i=1;i<=n;i++)
            ans=ans+'9';
        memset(dp,-1,sizeof(dp));
        return dpCalculate(ans,n+1,0,1,1,0,0);        
    }
};