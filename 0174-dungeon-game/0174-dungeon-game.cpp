class Solution {
public:
    int x[2] = {0, 1};
    int y[2] = {1, 0};
    int check(int m, vector<vector<int>>& dun) {
        m = m + dun[0][0];
        if (m <= 0)
            return 0;
        vector<vector<int>> dis(dun.size(), vector<int>(dun[0].size(), -1));
        dis[0][0]=m;
        priority_queue<tuple<int, int, int>> q;
        q.push({m, 0, 0});
        if(dun.size()-1==0 && dun[0].size()-1==0){
            return m>0;
        }
        while (!q.empty()) {
            auto [c, i, j] = q.top();
            q.pop();
            for (int z = 0; z < 2; z++) {
                int x1 = i + x[z];
                int y1 = j + y[z];
                if (x1 >= 0 && x1 < dun.size() && y1 >= 0 &&
                    y1 < dun[0].size()) {
                    if (x1 == dun.size() - 1 && y1 == dun[0].size() - 1 && c+dun[x1][y1]>0)
                        return c + dun[x1][y1];
                    if (dis[x1][y1] < c + dun[x1][y1] && c + dun[x1][y1] > 0) {
                        dis[x1][y1] = c + dun[x1][y1];
                        q.push({dis[x1][y1], x1, y1});
                    }
                }
            }
        }
        return 0;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 1, h = 1e9;
        int ans = 1;
        while (l <= h) {
            int m = (l + h) / 2;
            cout << m << " ";
            if (check(m, dungeon)>0) {
                ans = m;
                h = m - 1;
            } else
                l = m + 1;
        }
        return ans;
    }
};