class Solution {
public:
    int dij(vector<vector<pair<int,int>>>&adj,int thres,int n,int i){
        vector<int>dis(n,INT_MAX);
        dis[i]=0;
        priority_queue<tuple<int,int>,vector<tuple<int,int>>,greater<tuple<int,int>>>q;
        q.push({0,i});
        while(!q.empty()){
            auto [cost,node]=q.top();
            q.pop();
            for(auto j:adj[node]){
                int newCost=j.second;
                if(dis[j.first]>newCost+cost){
                    dis[j.first]=newCost+cost;
                    q.push({dis[j.first],j.first});
                }
            }
        }
        int c=0;
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]<=thres && dis[i]!=0)
            c++;
        }
        return c;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(dij(adj,distanceThreshold,n,i));   
        }
        int mini=*min_element(ans.begin(),ans.end());
        int node=0;
        for(int i=0;i<ans.size();i++){
            if(mini==ans[i])
            node=i;
        }
        return node;
    }
};