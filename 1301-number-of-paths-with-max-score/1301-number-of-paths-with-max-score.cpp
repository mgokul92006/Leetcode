class Solution {
public:
    int maxi=0,count=0,mod=1e9+7;
    int dpCalculate1(vector<string>&board,int i,int j,int sum,vector<vector<vector<int>>>&dp1){
        if(i==0 && j==0){
            return sum==maxi?1:0;
        }
        if(board[i][j]=='X')
        return 0;
        if(sum>maxi)
        return 0;
        if(dp1[i][j][sum]!=-1)
        return dp1[i][j][sum];
        int ans=0;
        if(i-1>=0)
            if(board[i][j]=='S')
                ans=(ans+(dpCalculate1(board,i-1,j,sum,dp1))%mod)%mod;
            else
                ans=(ans+(dpCalculate1(board,i-1,j,sum+board[i][j]-'0',dp1))%mod)%mod;
        if(i-1>=0 && j-1>=0 )
            if(board[i][j]=='S')
                ans=(ans+(dpCalculate1(board,i-1,j-1,sum,dp1))%mod)%mod;
            else
                ans=(ans+(dpCalculate1(board,i-1,j-1,sum+board[i][j]-'0',dp1))%mod)%mod;
        if(j-1>=0)
            if(board[i][j]=='S')
                ans=(ans+(dpCalculate1(board,i,j-1,sum,dp1))%mod)%mod;
            else
                ans=(ans+(dpCalculate1(board,i,j-1,sum+board[i][j]-'0',dp1))%mod)%mod;
        return dp1[i][j][sum]=ans;
    }
    int dpCalculate(vector<string>&board,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 0;
        }
        if(board[i][j]=='X')
        return -1e7;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=-1e7;
        if(i-1>=0)
            ans=max(ans,dpCalculate(board,i-1,j,dp));
        if(i-1>=0 && j-1>=0)
            ans=max(ans,dpCalculate(board,i-1,j-1,dp));
        if(j-1>=0)
            ans=max(ans,dpCalculate(board,i,j-1,dp));
        if(board[i][j]!='S')
        ans=ans+(board[i][j]-'0');
        return dp[i][j]=ans;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size()-1,m=board[0].size()-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int c=dpCalculate(board,n,m,dp);
        maxi=c;
        if(c<0)
        return {0,0};
        vector<vector<vector<int>>>dp1(n+1,vector<vector<int>>(m+1,vector<int>(maxi+1,-1)));
        count=dpCalculate1(board,n,m,0,dp1);
        return {c,count};
    }
};