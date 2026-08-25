class Solution {
public:
    bool check(int m,int s,int t,int k,vector<vector<pair<int,int>>>&adj,int n){
        vector<int>vis(n,INT_MAX);
        vis[s]=0;
        queue<tuple<int,int>>q;
        q.push({s,0});
        while(!q.empty()){
            auto [node,limit]=q.front();
            q.pop();
            for(auto l:adj[node]){
                int w=l.second;
                int newLimit=limit+(w>m?1:0);
                if(vis[l.first]>newLimit && newLimit<=k){
                    vis[l.first]=newLimit;
                    q.push({l.first,newLimit});
                }
            }
        }
        return vis[t]<=k;
    }
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            if(mini>edges[i][2])
            mini=edges[i][2];
            if(maxi<edges[i][2])
            maxi=edges[i][2];
        }
        int l=0,h=maxi,ans=-1;
        if(source==target)
        return 0;
        while(l<=h){
            int m=(l+h)/2;
            if(check(m,source,target,k,adj,n)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};