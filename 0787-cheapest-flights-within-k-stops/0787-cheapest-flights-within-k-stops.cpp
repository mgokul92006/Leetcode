class Solution {
public:
    int dij(vector<vector<pair<int,int>>>&adj,int src,int dst,int k,int n){
        vector<vector<int>>dis(n,vector<int>(k+2,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        dis[src][0]=0;
        q.push({0,0,src});
        while(!q.empty()){
            auto [cost,st,node]=q.top();
            q.pop();
            if(node==dst)
            return cost;
            for(auto i:adj[node]){
                int newCost=cost+i.second;
                int newStop=st+1;
                if(newStop<=k+1 && dis[i.first][newStop]>newCost){
                    dis[i.first][newStop]=newCost;
                    q.push({newCost,newStop,i.first});
                }
            }
        }
        return -1;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        return dij(adj,src,dst,k,n);
    }
};