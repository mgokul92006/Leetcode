class Solution {
public:
    int dpCalculate(vector<vector<int>>&grid,int k,int i,int j,int dir,int c,vector<vector<vector<vector<int>>>>&dp){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        return 1e9;
        if(c>k)
        return 1e9;
        if(i==grid.size()-1 && j==grid[0].size()-1)
        return grid[i][j];
        if(dp[i][j][dir+1][c]!=-1)
        return dp[i][j][dir+1][c];
        int ans=1e9;
        if(dir==-1){
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i+1,j,1,0,dp));
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i,j+1,2,0,dp));
        }
        if(i+1<grid.size() && dir==1)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i+1,j,dir,c,dp));
        if(i+1<grid.size() && dir!=1)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i+1,j,1,c+1,dp));
        if(i-1>=0 && dir==0)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i-1,j,dir,c,dp));
        if(i-1>=0 && dir!=0)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i-1,j,0,c+1,dp));
        if(j+1<grid[0].size() && dir==2)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i,j+1,dir,c,dp));
        if(j+1<grid[0].size() && dir!=2)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i,j+1,2,c+1,dp));
        if(j-1>=0 && dir==3)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i,j-1,dir,c,dp));
        if(j-1>=0 && dir!=3)
            ans=min(ans,grid[i][j]+dpCalculate(grid,k,i,j-1,3,c+1,dp));
        return dp[i][j][dir+1][c]=ans;
    }
    int minCost(vector<vector<int>>& grid, int k) {
        vector<vector<vector<vector<int>>>>dp(grid.size(),vector<vector<vector<int>>>(grid[0].size(),vector<vector<int>>(5,vector<int>(k+1,-1))));
        int p=dpCalculate(grid,k,0,0,-1,0,dp);
        if(p==1e9)
        return -1;
        return p;
    }
};