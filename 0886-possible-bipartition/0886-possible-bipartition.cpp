class Solution {
public:
    void bfs(vector<int>&vis,vector<int>&ans,int i,vector<vector<int>>&adj){
        vis[i]=1;
        queue<tuple<int,bool>>q;
        q.push({i,1});
        while(!q.empty()){
            auto [node,group]=q.front();
            q.pop();
            ans[node]=group;
            for(auto j:adj[node]){
                if(vis[j]==0){
                    vis[j]=1;
                    q.push({j,!group});
                }
            }
        }
        return ;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>ans(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                bfs(vis,ans,i,adj);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j:adj[i]){
                if(ans[i]==ans[j])
                return 0;
            }
        }
        return 1;
    }
};