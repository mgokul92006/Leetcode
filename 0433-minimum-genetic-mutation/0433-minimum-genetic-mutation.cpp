class Solution {
public:
    int path(string startGene,string endGene,set<string>&s){
        queue<tuple<string,int>>q;
        q.push({startGene,0});
        s.insert(startGene);
        set<string>vis;
        vis.insert(startGene);
        vector<char>c={'A','C','G','T'};
        while(!q.empty()){
            auto [st,steps]=q.front();
            q.pop();
            if(st==endGene)
            return steps;
            for(int i=0;i<st.size();i++){
                string temp=st;
                for(int j=0;j<c.size();j++){
                    temp[i]=c[j];
                    if(s.find(temp)!=s.end() && vis.find(temp)==vis.end()){
                        vis.insert(temp);
                        q.push({temp,steps+1});
                    }
                }
            }
        }
        return -1;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string>s;
        for(auto i:bank)
            s.insert(i);
        return path(startGene,endGene,s);
    }
};