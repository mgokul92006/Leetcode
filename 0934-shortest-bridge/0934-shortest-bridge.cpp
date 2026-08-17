class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    queue<tuple<int,int,int>>q;
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        q.push({0,i,j});
        for(int z=0;z<4;z++){
            int x1=i+x[z];
            int y1=j+y[z];
            if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size() && !vis[x1][y1] && grid[x1][y1]==1){
                dfs(x1,y1,grid,vis);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0 && c==0){
                    dfs(i,j,grid,vis);
                    c=1;
                }
            }
        }
        while(!q.empty()){
            auto [st,i,j]=q.front();
            q.pop();
            for(int z=0;z<4;z++){
                int x1=i+x[z];
                int y1=j+y[z];
                if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size()){
                    if(grid[x1][y1]==1 && !vis[x1][y1])
                    return st;
                    if(!vis[x1][y1]){
                    q.push({st+1,x1,y1});
                    vis[x1][y1]=1;
                    }
                }
            }
        }
        return 0;
    }
};