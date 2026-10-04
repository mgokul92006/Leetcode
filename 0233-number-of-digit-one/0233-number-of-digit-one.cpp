class Solution {
public:
    int dpCalculate(string& b,int i,int tight,int count,vector<vector<vector<int>>>&dp){
        if(b.size()==i)
        return count;
        if(dp[i][tight][count]!=-1)
        return dp[i][tight][count];
        int ans=0;
        int ub=(tight==1)?b[i]-'0':9;
        for(int j=0;j<=ub;j++){
            ans=ans+dpCalculate(b,i+1,(tight && ub==j),count+(j==1),dp);
        }
        return dp[i][tight][count]=ans;
    }
    int countDigitOne(int n) {
        string b=to_string(n);
        vector<vector<vector<int>>>dp(b.size(),vector<vector<int>>(2,vector<int>(10,-1)));
        return dpCalculate(b,0,1,0,dp);
    }
};