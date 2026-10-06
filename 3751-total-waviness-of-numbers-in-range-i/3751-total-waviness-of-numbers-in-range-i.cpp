class Solution {
public:
    int dp[6][2][12][12][4][2];
    int dpCalculate(string& a,int i,int tight,int first,int second,int count,int lz){
        if(i==a.size())
        return count;
        int ans=0;
        int ub=(tight==1)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(lz && j==0)
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),11,11,count,(lz && j==0));
            if(first==11 && !(lz && j==0))
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),j,11,count,(lz && j==0));
            else if(second==11 && !(lz && j==0))
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),first,j,count,(lz && j==0));
            if(first != 11 && second != 11){
                int c=0;
                if(j<second && second>first)
                    c++;
                else if(j>second && second<first)
                    c++;
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),second,j,count+c,(lz && j==0));
            }
        }
        return ans;
    }
    int totalWaviness(int num1, int num2) {
        string low=to_string(num1-1),high=to_string(num2);
        memset(dp,-1,sizeof(dp));
        int a=dpCalculate(high,0,1,11,11,0,1);
        memset(dp,-1,sizeof(dp));
        int b=dpCalculate(low,0,1,11,11,0,1);
        cout<<a<<" "<<b;
        return a-b;
    }
};