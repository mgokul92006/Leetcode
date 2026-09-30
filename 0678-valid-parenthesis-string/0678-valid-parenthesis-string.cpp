class Solution {
public:
    bool dpCalculate(string& s,int i,int ans1,vector<vector<int>>&dp){
        if(i==s.size()){
            if(ans1==0)
            return 1;
            return 0;
        }
        if(ans1<0)
        return 0;
        if(dp[i][ans1]!=-1)
        return dp[i][ans1];
        bool c=0;
        if(s[i]=='*'){
            c=c || dpCalculate(s,i+1,ans1+1,dp);
            c=c || dpCalculate(s,i+1,ans1-1,dp);
            c=c || dpCalculate(s,i+1,ans1,dp);
        }
        else{
            if(s[i]=='(')
            c=c|| dpCalculate(s,i+1,ans1+1,dp);
            else
            c=c || dpCalculate(s,i+1,ans1-1,dp);
        }
        return dp[i][ans1]=c;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(105,-1));
        return dpCalculate(s,0,0,dp);
    }
};