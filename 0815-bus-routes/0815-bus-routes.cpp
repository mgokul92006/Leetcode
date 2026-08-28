class Solution {
public:
    int bfs(map<int, vector<int>>& mp, int s, int t,
            vector<vector<int>>& routes) {
        unordered_set<int> s1;
        s1.insert(s);
        queue<tuple<int, int>> q;
        q.push({s, 0});
        while (!q.empty()) {
            auto [node, step] = q.front();
            q.pop();
            if (node == t)
                return step;
            auto l = mp[node];
            for (int i = 0; i < l.size(); i++) {
                for(auto j:routes[l[i]]){
                    if (s1.find(j) == s1.end()) {
                        s1.insert(j);
                        q.push({j, step + 1});
                    }
                }
                routes[l[i]].clear();
            }
        }
        return -1;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        map<int, vector<int>> mp;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                mp[routes[i][j]].push_back(i);
            }
        }
        return bfs(mp, source, target, routes);
    }
};