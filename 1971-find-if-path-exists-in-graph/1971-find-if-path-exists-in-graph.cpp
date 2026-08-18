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
    void merge(int u,int v){
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);
        if(ulp_u==ulp_v)
        return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]=size[ulp_v]+size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]=size[ulp_u]+size[ulp_v];
        }
    }

};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        Union* u=new Union(n);
        for(int i=0;i<edges.size();i++){
            u->merge(edges[i][0],edges[i][1]);
        }
        return u->find_parent(source)==u->find_parent(destination);
    }
};