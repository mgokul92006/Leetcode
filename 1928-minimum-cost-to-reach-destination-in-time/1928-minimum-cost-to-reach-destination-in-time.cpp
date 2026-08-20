class Solution {
public:
    int dij(vector<vector<pair<int,int>>>&adj,int maxTime,vector<int>& Fees,int n){
        vector<int>dis(n,INT_MAX);
        dis[0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        q.push({Fees[0],0,0});
        while(!q.empty()){
            auto [cost,time,node]=q.top();
            q.pop();
            if(node==n-1)
            return cost;
            for(auto i:adj[node]){
                int newCost=cost+Fees[i.first];
                int newTime=time+i.second;
                if(dis[i.first]>newTime && newTime<=maxTime){
                    dis[i.first]=newTime;
                    q.push({newCost,newTime,i.first});
                }
            }
        }
        return -1;
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n=passingFees.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        return dij(adj,maxTime,passingFees,n);
    }
};