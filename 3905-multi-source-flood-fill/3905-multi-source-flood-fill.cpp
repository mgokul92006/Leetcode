class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < sources.size(); i++) {
            ans[sources[i][0]][sources[i][1]] = sources[i][2];
            q.push({sources[i][2], {sources[i][0], sources[i][1]}});
            dis[sources[i][0]][sources[i][1]] = 0;
        }
        while (!q.empty()) {
            auto k = q.front();
            int c = k.first;
            int a = k.second.first;
            int b = k.second.second;
            q.pop();
            for (int p = 0; p < 4; p++) {
                int x1 = a + x[p];
                int y1 = b + y[p];
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m) {
                    int d = dis[a][b] + 1;
                    if (d < dis[x1][y1]) {
                        ans[x1][y1] = c;
                        q.push({c, {x1, y1}});
                        dis[x1][y1] = d;
                    } else if (d == dis[x1][y1] && c > ans[x1][y1]) {
                        ans[x1][y1] = c;
                        q.push({c, {x1, y1}});
                        dis[x1][y1] = d;
                    }
                }
            }
        }
        return ans;
    }
};