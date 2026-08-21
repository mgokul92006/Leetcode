class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<bool>>vis(n,vector<bool>(1<<n,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            int mask=1<<i;
            vis[i][mask]=1;
            q.push({i,mask,0});
        }
        int final=(1<<n)-1;
        while(!q.empty()){
            auto [node,mask,st]=q.front();
            q.pop();
            if(final==mask)
                return st;
            for(auto i:graph[node]){
                int newMask=mask | (1<<i);
                if( !vis[i][newMask] ){
                    vis[i][newMask]=1;
                    q.push({i,newMask,st+1});
                }
            }
        }
        return 0;
    }
};