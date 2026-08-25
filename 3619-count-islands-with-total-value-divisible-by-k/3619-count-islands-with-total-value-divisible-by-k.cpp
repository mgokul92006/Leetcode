class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int bfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int i,int j,int k){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int c=grid[i][j];
        while(!q.empty()){
            int m=q.front().first;
            int n=q.front().second;
            q.pop();
            for(int z=0;z<4;z++){
                int x1=m+x[z];
                int y1=n+y[z];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && grid[x1][y1]!=0 && vis[x1][y1]==0){
                    vis[x1][y1]=1;
                    q.push({x1,y1});
                    c=(c+(grid[x1][y1]%k))%k;
                }
            }
        }
        return c%k==0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int maxi=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    maxi=maxi+bfs(grid,vis,i,j,k);
                }
            }
        }
        return maxi;
    }
};