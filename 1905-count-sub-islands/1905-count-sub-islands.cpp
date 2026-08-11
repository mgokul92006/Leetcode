class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int bfs(vector<vector<int>>&vis,vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        bool flag=1;
        vis[i][j]=1;
        if(grid1[i][j]==0 && grid2[i][j]==1)
        flag=0;
        queue<tuple<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto [n,m]=q.front();
            q.pop();
            for(int z=0;z<4;z++){
                int x1=x[z]+n;
                int y1=y[z]+m;
                if(x1>=0 && y1>=0 && x1<grid1.size() && y1<grid1[0].size()){
                    if(grid1[x1][y1]==0 && grid2[x1][y1]==1){
                    flag=0;
                    }
                    if(grid2[x1][y1]==1 && !vis[x1][y1]){
                        q.push({x1,y1});
                        vis[x1][y1]=1;
                    }
                }
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int c=0;
        vector<vector<int>>vis(grid1.size(),vector<int>(grid1[0].size(),0));
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[0].size();j++){
                if(!vis[i][j] && grid2[i][j]==1){
                    c=c+bfs(vis,grid1,grid2,i,j);
                }
            }
        }
        return c;
    }
};