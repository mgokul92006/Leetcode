class Solution {
public:
    double path(vector<vector<pair<int,double>>>&adj,int start,int end,int n){
        vector<double>dis(n,0);
        priority_queue<tuple<double,int>>q;
        q.push({1.0,start});
        while(!q.empty()){
            auto [cost,node]=q.top();
            q.pop();
            for(auto k:adj[node]){
                double newCost=k.second*cost;
                if(newCost>dis[k.first]){
                    dis[k.first]=newCost;
                    q.push({newCost,k.first});
                }
            }
        }
        return dis[end];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        int j=0;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],succProb[j]});
            adj[i[1]].push_back({i[0],succProb[j]});
            j++;
        }
        return path(adj,start_node,end_node,n);
    }
};