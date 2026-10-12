class Solution {
public:
    int mod=1e9+7;
    int dpCalculate(int n,vector<char>&s,int prev,vector<vector<int>>&dp){
        if(n==0)
        return 1;
        if(dp[n][prev+1]!=-1)
        return dp[n][prev+1];
        int ans=0;
        for(int j=0;j<s.size();j++){
            if(prev==-1)
                ans=(ans+dpCalculate(n-1,s,j,dp))%mod;
            if(prev!=-1 && s[j]=='e' && s[prev]=='a')
                ans=(ans+dpCalculate(n-1,s,j,dp))%mod;
            if( prev!=-1 && (s[j]=='a' || s[j]=='i') && s[prev]=='e')
                ans=(ans+dpCalculate(n-1,s,j,dp))%mod;
            if(prev!=-1 &&  s[prev]=='o' && (s[j]=='i' || s[j]=='u'))
                ans=(ans+dpCalculate(n-1,s,j,dp))%mod;
            if(prev!=-1 && s[prev]=='u' && (s[j]=='a'))
                ans=(ans+dpCalculate(n-1,s,j,dp))%mod;
            if(prev!=-1 && s[prev] == 'i' && s[j]!='i')
                ans=(ans+dpCalculate(n-1,s,j,dp))%mod;
        }
        return dp[n][prev+1]=ans%mod;
    }
    int countVowelPermutation(int n) {
        vector<char>s={'a','e','i','o','u'};
        int prev=-1;
        vector<vector<int>>dp(n+1,vector<int>(7,-1));
        return dpCalculate(n,s,prev,dp);
    }
};