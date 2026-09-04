class Solution {
public:
    int kSimilarity(string s1, string s2) {
        set<string>vis;
        vis.insert(s1);
        queue<pair<string,int>>q;
        q.push({s1,0});
        while(!q.empty()){
            auto [st,step]=q.front();
            q.pop();
            if(st==s2)
            return step;
            int i=0;
            for(i=0;i<st.size();i++){
                if(st[i]!=s2[i])
                break;
            }
            int j=i+1;
            char w=s2[i];
            while(j<st.size()){
                if(w==st[j]){
                    string temp=st;
                    swap(temp[j],temp[i]);
                    if(vis.find(temp)==vis.end()){
                        q.push({temp,step+1});
                        vis.insert(temp);
                    }
                }
                j++;
            }
        }
        return 0;
    }
};