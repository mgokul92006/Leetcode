class Union{
    vector<int>par,size;
    public:
    Union(int n){
        par.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
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
        if(size[ulp_v]<size[ulp_u]){
            par[ulp_v]=ulp_u;
            size[ulp_u]=size[ulp_u]+size[ulp_v];
        }
        else{
            par[ulp_u]=ulp_v;
            size[ulp_v]=size[ulp_v]+size[ulp_u];
        }
    }
    void print(){
        for(auto i:par){
            cout<<i<<" ";
        }
    }
    string find(string& s){
        string ans="";
        unordered_map<int,multiset<char>>mp;
        for(int i=0;i<par.size();i++){
            mp[par[i]].insert(s[i]);
        }
        for(int i=0;i<s.size();i++){
            int par1=par[i];
            ans+=*mp[par1].begin();
            mp[par1].erase(mp[par1].begin());
        }
        return ans;
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        Union* n=new Union(s.size());
        for(int i=0;i<pairs.size();i++){
            n->merge(pairs[i][0],pairs[i][1]);
        }
        for(int i = 0 ; i < s.size() ; i++ )
            n->find_parent(i);
        return n->find(s);
    }
};