class Union{
    vector<int>parent,size;
    public:
    Union(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=0;
        }
    }
    int find_parent(int u){
        if(u==parent[u])
        return u;
        return parent[u]=find_parent(parent[u]);
    }
    int merge(int u,int v){
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);
        if(ulp_u==ulp_v)
        return 1;
        if(size[ulp_v]<size[ulp_u]){
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        return 0;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        Union* u=new Union(isConnected.size());
        vector<vector<int>>adj(isConnected.size());
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    u->merge(i,j);
                }
            }
        }
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<isConnected.size();i++){
            int root=u->find_parent(i);
            mp[root].push_back(i);
        }
        return mp.size();
    }
};