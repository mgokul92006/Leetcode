class Solution {
public:
    int dij(vector<vector<pair<int,int>>>&adj,int maxTime,vector<int>& Fees,int n){
        vector<vector<int>>dis(n,vector<int>(maxTime+1,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        q.push({Fees[0],0,0});
        while(!q.empty()){
            auto [cost,time,node]=q.top();
            q.pop();
            for(auto i:adj[node]){
                int newCost=cost+Fees[i.first];
                int newTime=time+i.second;
                if(newTime<=maxTime && dis[i.first][newTime]>newCost){
                    dis[i.first][newTime]=newCost;
                    q.push({newCost,newTime,i.first});
                }
            }
        }
        int mini=1e9;
        for(int i=0;i<dis[n-1].size();i++){
            mini=min(mini,dis[n-1][i]);
        }
        return mini==1e9?-1:mini;
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