class Solution {
public:
    int x[8]={1,-1,0,0,1,1,-1,-1};
    int y[8]={0,0,1,-1,-1,1,-1,1};
    int path(vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[0][0]=1;
        queue<tuple<int,int,int>>q;
        q.push({0,0,1});
        while(!q.empty()){
            auto [i,j,c]=q.front();
            q.pop();
            for(int z=0;z<8;z++){
                int x1=i+x[z];
                int y1=j+y[z];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size()){
                    if(x1==grid.size()-1 && y1==grid[0].size()-1 && grid[x1][y1]!=1)
                    return c+1;
                    else if(vis[x1][y1]>1+c && grid[x1][y1]!=1){
                        vis[x1][y1]=1+c;
                        q.push({x1,y1,vis[x1][y1]});
                    }
                }
            }
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        if(grid[0][0])
        return -1;
        if(grid.size()==1 && grid[0].size()==1)
        return 1;
        return path(grid,vis);
    }
};