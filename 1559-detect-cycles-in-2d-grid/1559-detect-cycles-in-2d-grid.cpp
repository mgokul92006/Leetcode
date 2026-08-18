class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    bool bfs(int i, int j, vector<vector<char>>& grid,vector<vector<int>>&vis) {
        char k = grid[i][j];
        queue<tuple<int, int,int>> q;
        q.push({i, j,1});
        vis[i][j]=1;
        while (!q.empty()) {
            auto [i1, j1,dis] = q.front();
            q.pop();
            for (int z = 0; z < 4; z++) {
                int x1 = i1 + x[z];
                int y1 = j1 + y[z];
                if (x1 >= 0 && y1 >= 0 && x1 < grid.size() &&
                    y1 < grid[0].size()) {
                    if (k == grid[x1][y1] && vis[x1][y1]==0) {
                        q.push({x1, y1,dis+1});
                        vis[x1][y1] = 1+dis;
                    }
                    else if (vis[x1][y1]>0 && vis[x1][y1]>=dis && k==grid[x1][y1])
                        return 1;
                }
            }
        }
        return 0;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (vis[i][j]==0 && bfs(i, j, grid,vis) == true)
                    return true;
            }
        }
        return false;
    }
};