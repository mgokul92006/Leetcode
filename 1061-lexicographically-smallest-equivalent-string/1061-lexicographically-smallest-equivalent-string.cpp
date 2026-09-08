class Union{
    vector<int>par;
    public:
    Union(int n){
        par.resize(26);
        for(int i=0;i<26;i++){
            par[i]=i;
        }
    }
    int find_parent(int a){
        if(a==par[a])
        return a;
        return par[a]=find_parent(par[a]);
    }
    void merge(int a,int b){
        int ulp_a=find_parent(a);
        int ulp_b=find_parent(b);
        if(ulp_a==ulp_b)
        return;
        if(ulp_a<ulp_b){
            par[ulp_b]=ulp_a;
        }
        else
            par[ulp_a]=ulp_b;
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Union* n=new Union(26);
        for(int i=0;i<s1.size();i++){
            char a=s1[i],b=s2[i];
            n->merge(a-'a',b-'a');
        }
        string ans="";
        for(int i=0;i<baseStr.size();i++){
            int b=n->find_parent(baseStr[i]-'a');
            ans=ans+(char)(b+'a');
        }
        return ans;
    }
};