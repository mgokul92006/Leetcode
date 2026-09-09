class Union {
    vector<int> par, size;

public:
    Union(int n) {
        par.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int find_parent(int u) {
        if (u == par[u])
            return u;
        return par[u] = find_parent(par[u]);
    }
    void merge(int u, int v) {
        int ulp_u = find_parent(u);
        int ulp_v = find_parent(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            par[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_v] + size[ulp_u];
        } else {
            par[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u] + size[ulp_v];
        }
    }
    void print(){
        for(auto& i:size)
            cout<<i<<" ";
    }
    int sum(int u) { return size[u]; }
};
class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};
    int largestIsland(vector<vector<int>>& grid) {
        int i1 = grid.size(), j1 = grid[0].size();
        Union* n = new Union(i1 * j1);
        for (int i = 0; i < i1; i++) {
            for (int j = 0; j < j1; j++) {
                if (grid[i][j] == 1) {
                    int node = i * j1 + j;
                    for (int z = 0; z < 4; z++) {
                        int x1 = x[z] + i;
                        int y1 = y[z] + j;
                        if (x1 >= 0 && y1 >= 0 && x1 < i1 && y1 < j1 &&
                            grid[x1][y1] == 1) {
                            int node1 = x1 * j1 + y1;
                            if (n->find_parent(node) != n->find_parent(node1)) {
                                n->merge(node, node1);
                            }
                        }
                    }
                }
            }
        }
        n->print();
        int maxi = 0;
        for (int i = 0; i < i1; i++) {
            for (int j = 0; j < j1; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int>st;
                    int sum=0;
                    for (int z = 0; z < 4; z++) {
                        int x1 = x[z] + i;
                        int y1 = y[z] + j;
                        if (x1 >= 0 && y1 >= 0 && x1 < i1 && y1 < j1 && grid[x1][y1] == 1) {
                            int node1 = x1 * j1 + y1;
                            if(st.find(n->find_parent(node1))==st.end()){
                                sum=sum+n->sum(n->find_parent(node1));
                                st.insert(n->find_parent(node1));
                            }
                        }
                    }
                    maxi=max(maxi,sum+1);
                }
            }
        }
        if(maxi==0){
            for(int i=0;i<i1;i++){
                for(int j=0;j<j1;j++){
                    int node=i*j1+j;
                    maxi=max(maxi,n->sum(n->find_parent(node)));
                }
            }
        }
        return maxi;
    }
};