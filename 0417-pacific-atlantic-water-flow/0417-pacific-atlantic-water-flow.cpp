class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    void bfs(int i1, int j1, vector<vector<int>>& paci,
             vector<vector<int>>& heights, int n, int m) {
        paci[i1][j1] = 1;
        queue<tuple<int, int>> q;
        q.push({i1, j1});
        while (!q.empty()) {
            auto [i1, j1] = q.front();
            q.pop();
            for (int z = 0; z < 4; z++) {
                int x1 = i1 + x[z];
                int y1 = j1 + y[z];
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m &&
                    paci[x1][y1] == 0) {
                    if (heights[i1][j1] <= heights[x1][y1]) {
                        paci[x1][y1] = 1;
                        q.push({x1, y1});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> paci(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            bfs(0, i, paci, heights, n, m);
        }
        for (int i = 0; i < n; i++) {
            bfs(i, 0, paci, heights, n, m);
        }
        for (int i = m-1; i>=0; i--) {
            bfs(n-1, i, atl, heights, n, m);
        }
        for (int i = n-1; i>=0; i--) {
            bfs(i, m-1, atl, heights, n, m);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (paci[i][j] == 1 && atl[i][j] == 1)
                    ans.push_back({i, j});
        }
        return ans;
    }
};