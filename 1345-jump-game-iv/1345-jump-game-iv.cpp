class Solution {
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]].push_back(i);
        queue<tuple<int,int>>q;
        q.push({0,0});
        vector<int>vis(arr.size(),0);
        vis[0]=1;
        while(!q.empty()){
            auto [st,node]=q.front();
            q.pop();
            if(node==arr.size()-1)
            return st;
            if(node+1<arr.size() && vis[node+1]==0){
                q.push({st+1,node+1});
                vis[node+1]=1;
            }
            if(node-1>=0 && vis[node-1]==0){
                q.push({st+1,node-1});
                vis[node-1]=1;
            }
            if(mp.find(arr[node])!=mp.end()){
                auto k=mp[arr[node]];
                for(int i=0;i<k.size();i++){
                    if(vis[k[i]]==0){
                        q.push({st+1,k[i]});
                        vis[k[i]]=1;
                    }
                }
                mp[arr[node]].clear();
            }
        }
        return -1;
    }
};