class Union{
    vector<int>par,size;
    public:
    Union(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            par[i]=i;
    }
    int find_parent(int u){
        if(u==par[u])
        return u;
        return par[u]=find_parent(par[u]);
    }
    void merge(int u,int v){
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);
        if(ulp_u==ulp_v)
        return;
        if(size[ulp_u]<size[ulp_v]){
            par[ulp_u]=ulp_v;
            size[ulp_v]=size[ulp_v]+size[ulp_u];
        }
        else{
            par[ulp_v]=ulp_u;
            size[ulp_u]=size[ulp_u]+size[ulp_v];
        }
    }
    int countNodes(){
        int c=0;
        for(auto i:par){
            if(size[i]>1)
            c++;
        }
        return c;
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int i1=grid.size(),j1=grid[0].size();
        int n1=i1*j1;
        Union* n=new Union(n1);
        for(int i=0;i<i1;i++){
            for(int j=0;j<j1;j++){
                if(grid[i][j]==0){
                    continue;
                }
                int node=i*j1+j;
                for(int z=0;z<i1;z++){
                    if(grid[z][j]==1 && z!=i){
                        int node1=z*j1+j;
                        n->merge(node,node1);
                    }
                }
                for(int z=0;z<j1;z++){
                    if(grid[i][z]==1 && z!=j){
                        int node1=i*j1+z;
                        n->merge(node,node1);
                    }
                }
            }
        }
        return n->countNodes();
    }
};