class Solution {
public:
    int bfs(set<int>&s,int a,int b,int x){
        queue<tuple<int,int,int>>q;
        q.push({0,0,0});
        int limit=a+b+max(x,*max_element(s.begin(),s.end()));
        vector<vector<int>>vis(limit+1,vector<int>(2,0));
        s.insert(0);
        while(!q.empty()){
            auto [back,node,step]=q.front();
            q.pop();
            if(node==x)
            return step;
            if(s.find(node+a)==s.end() && node+a<=limit && vis[node+a][0]==0){
                q.push({0,node+a,step+1});
                vis[node+a][0]=1;
            }
            if(back==0 && node-b>=0 && s.find(node-b)==s.end() && vis[node-b][1]==0){
                vis[node-b][1]=1;
                q.push({1,node-b,step+1});
            }
        }
        return -1;
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int>s(forbidden.begin(),forbidden.end());
        return bfs(s,a,b,x);
    }
};