class Solution {
public:
    long long dp[16][2][12][12][100][2];
    long long dpCalculate(string& n,int i,int tight,int first,int second,int count,int lz){
        if(n.size()==i)
        return count;
        if(dp[i][tight][first][second][count][lz]!=-1)
        return dp[i][tight][first][second][count][lz];
        long long ans=0;
        int ub=(tight==1)?n[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(j==0 && lz){
                ans=ans+dpCalculate(n,i+1,(tight && j==ub),11,11,count,(lz && j==0));
            }
            if(first==11 && !(j==0 && lz))
                ans=ans+dpCalculate(n,i+1,(tight && j==ub),j,11,count,(lz && j==0));
            else if(second==11 && !(j==0 && lz))
                ans=ans+dpCalculate(n,i+1,(tight && j==ub),first,j,count,(lz && j==0));
            if(first!=11 && second!=11)
            {
                if(second>first && second>j)
                    ans=ans+dpCalculate(n,i+1,(tight && j==ub),second,j,count+1,(lz && j==0));
                else if(second<j && second<first)
                    ans=ans+dpCalculate(n,i+1,(tight && j==ub),second,j,count+1,(lz && j==0));
                else
                    ans=ans+dpCalculate(n,i+1,(tight && j==ub),second,j,count,(lz && j==0));
            }
        }
        return dp[i][tight][first][second][count][lz]=ans;
    }
    long long totalWaviness(long long num1, long long num2) {
        string low=to_string(num1-1),high=to_string(num2);
        memset(dp,-1,sizeof(dp));
        long long a=dpCalculate(high,0,1,11,11,0,1);
        memset(dp,-1,sizeof(dp));
        long long b=dpCalculate(low,0,1,11,11,0,1);
        return a-b;
    }
};