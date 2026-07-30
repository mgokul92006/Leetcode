class Solution {
public:
    bool dfs(int i, vector<int>& vis, vector<vector<int>>& graph,
             vector<int>& ans, vector<int>& path) {
        vis[i] = 1;
        path[i] = 1;
        for (auto k : graph[i]) {
            if (!vis[k]) {
                if (dfs(k, vis, graph, ans, path)) {
                    ans[i] = 0;
                    return true;
                }
            } else if (path[k]) {
                ans[i] = 0;
                return true;
            }
        }
        ans[i] = 1;
        path[i] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int> path(graph.size(), 0);
        vector<int> ans(graph.size(), 0);
        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                dfs(i, vis, graph, ans, path);
            }
        }
        vector<int> safe;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 1)
                safe.push_back(i);
        }
        return safe;
    }
};