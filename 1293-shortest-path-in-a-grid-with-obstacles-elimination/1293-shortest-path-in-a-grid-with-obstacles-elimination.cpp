class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int path(vector<vector<int>>& grid,vector<vector<vector<int>>>& vis, int k){
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>q;
        if(grid.size()-1==0 && grid[0].size()-1==0){
            return 0;
        }
        if(grid[0][0])
        k--;
        int c=0;
        q.push({c,k,0,0});
        while(!q.empty()){
            auto [c,o,i,j]=q.top();
            q.pop();
            for(int z=0;z<4;z++){
                int x1=i+x[z];
                int y1=j+y[z];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size()){
                    if(c+1>vis[x1][y1][o])
                    continue;
                    if(x1==grid.size()-1 && y1==grid[0].size()-1){
                        return c+1;
                    }
                    else if(grid[x1][y1]==1 && o>0 && c+1<vis[x1][y1][o-1]){
                        q.push({c+1,o-1,x1,y1});
                        vis[x1][y1][o-1]=c+1;
                    }
                    else if(grid[x1][y1]==0 && c+1<vis[x1][y1][o]){
                        vis[x1][y1][o]=c+1;
                        q.push({c+1,o,x1,y1});
                    }
                }
            }
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>>vis(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(k+1,INT_MAX)));
        vis[0][0][k]=1;
        return path(grid,vis,k);
    }
};