class Solution {
public:
    int bfs(vector<vector<int>>&adj,int n,set<int>&res){
        queue<int>q;
        int c=1;
        vector<int>vis(n,0);
        vis[0]=1;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto p:adj[node]){
                if(vis[p]==0 && res.find(p)==res.end()){
                    vis[p]=1;
                    c++;
                    q.push(p);
                }
            }
        }
        return c;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        set<int>res;
        for(auto i:restricted)
            res.insert(i);
        return bfs(adj,n,res);
    }
};