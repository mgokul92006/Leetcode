class Solution {
public:
    int dp[10][2][2][25][22];
    int dpCalculate(string& num,int& k,int i,int tight,int lz,int diff,int sum){
        if(num.size()==i){
            if(!lz && diff==0 && sum==0)
            return 1;
            return 0;
        }
        if(dp[i][tight][lz][diff+10][sum]!=-1)
        return dp[i][tight][lz][diff+10][sum];
        int ans=0;
        int ub=(tight==1)?num[i]-'0':9;
        for(int j=0;j<=ub;j++){
            int c=0;
            if(!(j==0 && lz)){
            if(j%2==0)
                c++;
            else
                c--;
            }
            ans=ans+dpCalculate(num,k,i+1,(tight && j==ub),(j==0 && lz),diff+c,(sum*10+j)%k);
        }
        return dp[i][tight][lz][diff+10][sum]=ans;
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string a1=to_string(high);
        string b1=to_string(low-1);
        memset(dp,-1,sizeof(dp));
        int ans1=dpCalculate(a1,k,0,1,1,0,0);
        memset(dp,-1,sizeof(dp));
        int ans2=dpCalculate(b1,k,0,1,1,0,0);
        return ans1-ans2;
    }
};