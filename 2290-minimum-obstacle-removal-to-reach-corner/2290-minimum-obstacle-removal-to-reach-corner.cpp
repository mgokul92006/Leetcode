class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int path(vector<vector<int>>& vis, vector<vector<int>>& grid) {
        vis[0][0]=1;
        priority_queue<tuple<int, int, int>, vector<std::tuple<int, int, int>>,
                       greater<std::tuple<int, int, int>>>pq;
        pq.push({0,0,0});
        int cost,i,j;
        while(!pq.empty()){
            auto [cost,i,j]=pq.top();
            pq.pop();
            for(int z=0;z<4;z++){
                int x1=i+x[z];
                int y1=j+y[z];
                if(x1>=0 && x1<grid.size() && y1>=0 && y1<grid[0].size() && !vis[x1][y1]){
                    if(x1==grid.size()-1 && y1==grid[0].size()-1)
                    return cost;
                    else{
                        pq.push({cost+grid[x1][y1],x1,y1});
                    }
                    vis[x1][y1]=1;
                }
            }
        }
        return 0;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        return path(vis, grid);
    }
};