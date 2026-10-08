
class Solution {
public:
    int dp[101][2][12][2];
    int mod=1e9+7;
    int dpCalculate(string& a,int i,int tight,int prev,int lz){
        if(i==a.size())
        {
            return lz?0:1;
        }
        if(dp[i][tight][prev][lz]!=-1)
        return dp[i][tight][prev][lz];
        int ans=0;
        int ub=(tight==1)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(lz && j==0){
                ans=(ans+dpCalculate(a,i+1,(tight && j==ub),11,lz))%mod;
            }
            else{
                if(prev==11 || abs(prev-j)==1)
                    ans=(ans+dpCalculate(a,i+1,(tight && j==ub),j,(lz && j==0)))%mod;
            }
        }
        return dp[i][tight][prev][lz]=ans%mod;
    }
    int countSteppingNumbers(string low, string high) {
        memset(dp,-1,sizeof(dp));
        int a=dpCalculate(high,0,1,11,1)%mod;
        memset(dp,-1,sizeof(dp));
        int b=dpCalculate(low,0,1,11,1)%mod;
        int ans=1;
        for(int i=0;i<low.size()-1;i++){
            if((abs((low[i]-'0') - (low[i+1]-'0')))!=1){
                ans=0;
                break;
            }
        }
        a=(a+ans)%mod;
        return (a-b+mod)%mod;
    }
};