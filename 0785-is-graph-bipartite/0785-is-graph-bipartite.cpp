class Solution {
public:
    bool bfs(int i,vector<vector<int>>&graph,vector<int>&vis){
        vis[i]=0;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(int j:graph[n]){
                if(vis[j]==-1){
                    vis[j]=!vis[n];
                    q.push(j);
                }
                else if(vis[j]==vis[n])
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(vis[i]==-1){
                if(bfs(i,graph,vis)==false)
                return false;
            }
        }
        return true;
    }
};