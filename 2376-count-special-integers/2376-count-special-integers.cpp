class Solution {
public:
    int dp[11][2][2][1023][2];
    int dpCalculate(string& num,int i,int tight,int lz,int mask,int rep){
        if(i==num.size())
        return rep==1?0:1;
        if(dp[i][tight][lz][mask][rep]!=-1)
        return dp[i][tight][lz][mask][rep];
        int ans=0;
        int ub=(tight==1)?num[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(lz && j==0)
                ans=ans+dpCalculate(num,i+1,(tight && j==ub),lz,mask,rep);
            else{
                int in=1 & (mask>>j);
                ans=ans+dpCalculate(num,i+1,(tight && j==ub),(lz && j==0),mask | 1<<j,rep || in);

            }
        }
        return dp[i][tight][lz][mask][rep]=ans;
    }
    int countSpecialNumbers(int n) {
        string num=to_string(n);
        memset(dp,-1,sizeof(dp));
        return dpCalculate(num,0,1,1,0,0)-1;
    }
};