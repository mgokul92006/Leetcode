class Solution {
public:
    bool pali(int i,int j,string& s){
        while(i<j){
            if(s[i]!=s[j])
            return 0;
            i++;
            j--;
        }
        return 1;
    }
    int dpCalculate(int i,string& s,vector<int>&dp){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1)
        return dp[i];
        int ans=1e9;
        for(int j=i;j<s.size();j++){
            if(pali(i,j,s)){
                ans=min(ans,1+dpCalculate(j+1,s,dp));
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return dpCalculate(0,s,dp)-1;
    }
};