class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int bfs(int t,int s,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[t][s]=1;
        bool touch=false;
        queue<pair<int,int>>q;
        q.push({t,s});
        int c=0;
        if(t==0 || t==grid.size()-1 || s==0 || s==grid[0].size()-1)
        touch=true;
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x1=a+x[i];
                int y1=b+y[i];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && vis[x1][y1]==0 && grid[x1][y1]==1){
                    if(y1==0 || x1==0 || x1==grid.size()-1 || y1==grid[0].size()-1)
                    touch=true;
                    vis[x1][y1]=1;
                    c++;
                    q.push({x1,y1});
                }
            }
        }
        if(touch == false){
        return c+1;
        }
        return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int c=0;
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    c=c+bfs(i,j,vis,grid);
                }
            }
        }
        return c;
    }
};