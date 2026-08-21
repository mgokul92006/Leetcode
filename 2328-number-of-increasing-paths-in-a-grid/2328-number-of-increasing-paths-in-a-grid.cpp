class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int mod=1e9+7;
    int dpCalculate(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=1;
        for(int z=0;z<4;z++){
            int x1=i+x[z];
            int y1=j+y[z];
            if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size()){
                if(grid[i][j]<grid[x1][y1])
                    ans=(ans+(dpCalculate(x1,y1,grid,dp)%mod))%mod;
            }
        }
        return dp[i][j]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int c=0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                c=(c+(dpCalculate(i,j,grid,dp)%mod))%mod;
            }
        }
        return c;
    }
};