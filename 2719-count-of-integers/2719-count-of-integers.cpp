class Solution {
public:
    int dp[23][2][405];
    int mod=1e9+7;
    int dpCalculate(string& num,int& min_sum,int& max_sum,int i,int tight,int sum){
        if(num.size()==i){
            if(sum>=min_sum && sum<=max_sum)
            return 1;
            return 0;
        }
        if(dp[i][tight][sum]!=-1)
        return dp[i][tight][sum];
        int ans=0;
        int ub=(tight==1)?num[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(sum+j>max_sum)
            continue;
            ans=(ans+dpCalculate(num,min_sum,max_sum,i+1,(tight && ub==j),sum+j))%mod;
        }
        return dp[i][tight][sum]=ans%mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum) {
        int ans1=0,ans2=0;
        memset(dp,-1,sizeof(dp));
        ans1=dpCalculate(num2,min_sum,max_sum,0,1,0);
        memset(dp,-1,sizeof(dp));
        ans2=dpCalculate(num1,min_sum,max_sum,0,1,0);
        int c=0;
        for(auto i:num1)
            c=c+(i-'0');
        if(c>=min_sum && c<=max_sum)
            ans1=(ans1+1)%mod;
        return (ans1-ans2+mod)%mod;
    }
};