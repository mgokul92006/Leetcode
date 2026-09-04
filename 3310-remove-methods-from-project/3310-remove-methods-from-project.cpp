class Solution {
public:
    void bfs(vector<vector<int>>& adj, int n, int k, vector<int>& bug,
             vector<int>& vis) {
        vis[k] = 1;
        queue<int> q;
        q.push(k);
        bug.push_back(k);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto i : adj[node]) {
                if (vis[i] == 0) {
                    vis[i] = 1;
                    q.push(i);
                    bug.push_back(i);
                }
            }
        }
    }
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (auto i : invocations) {
            adj[i[0]].push_back(i[1]);
        }
        vector<int> bug;
        vector<int> vis(n, 0);
        bfs(adj, n, k, bug, vis);
        set<int> bug1;
        for (auto i : bug)
            bug1.insert(i);
        vector<int> nbug;
        for (int i = 0; i < n; i++)
            if (vis[i] == 0)
                nbug.push_back(i);
        for (auto& e : invocations) {
            int u = e[0], v = e[1];
            if (vis[u] == 0 && vis[v] == 1) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }
        return nbug;
    }
};