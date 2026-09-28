class Solution {
public:
    int dpCalculate(vector<vector<pair<int,int>>>&gr,int val,vector<int>&dp){
        if(gr[val].empty())
        return val;
        if(dp[val]!=-1)
        return dp[val];
        int ans=1e7;
        for(auto i:gr[val]){
            ans=min(ans,val+i.second+dpCalculate(gr,i.first,dp));
        }
        return dp[val]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int size=grid.size()*grid[0].size(),mini=INT_MAX;
        vector<vector<pair<int,int>>>gr(size);
        for(int i=0;i<grid.size()-1;i++){
            for(int j=0;j<grid[i].size();j++){
                for(int k=0;k<grid[i+1].size();k++){
                    int u=grid[i][j];
                    int v=grid[i+1][k];
                    int weight=moveCost[u][k];
                    gr[u].push_back({v,weight});
                }
            }
        }
        vector<int>dp(size,-1);
        for(int i=0;i<grid[0].size();i++){
            mini=min(mini,dpCalculate(gr,grid[0][i],dp));
        }
        return mini;
    }
};