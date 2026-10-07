class Solution {
public:
    int dp[10][2][2];
    int dpCalculate(set<int>&s,string& n,int i,int tight,int lz){
        if(i==n.size())
        return lz?0:1;
        if(dp[i][tight][lz]!=-1)
        return dp[i][tight][lz];
        int ans=0;
        int ub=(tight==1)?n[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(j==0 && lz){
                ans=ans+dpCalculate(s,n,i+1,tight && j==ub,lz);
            }
            if(s.find(j)==s.end())
            continue;
            else{
                ans=ans+dpCalculate(s,n,i+1,tight && j==ub,lz && j==0);
            }
        }
        return dp[i][tight][lz]=ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        set<int>s;
        for(int i=0;i<digits.size();i++){
            s.insert(digits[i][0]-'0');
        }
        string ans=to_string(n);
        memset(dp,-1,sizeof(dp));
        return dpCalculate(s,ans,0,1,1);
    }
};