class Solution {
public:
    void dfs(vector<vector<int>>&adj,int i,vector<int>&vis,int& tar,vector<int>&ans,vector<vector<int>>&ans1){
        if(i==tar){
        ans.push_back(i);
        ans1.push_back(ans);
        ans.pop_back();
        return;
        }
        ans.push_back(i);
        vis[i]=1;
        for(auto k:adj[i]){
            if(vis[k]==0){
                dfs(adj,k,vis,tar,ans,ans1);
            }
        }
        ans.pop_back();
        vis[i]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int tar=graph.size()-1;
        vector<vector<int>>adj(tar+1);
        for(int i=0;i<=tar;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>vis(tar+1,0);
        vector<vector<int>>ans1;
        vector<int>ans;
        dfs(adj,0,vis,tar,ans,ans1);
        return ans1;
    }
};