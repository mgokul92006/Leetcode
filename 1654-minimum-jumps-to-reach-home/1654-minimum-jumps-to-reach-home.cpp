class Solution {
public:
    int bfs(set<int>&s,int a,int b,int x){
        queue<tuple<int,int,int>>q;
        q.push({0,0,0});
        int limit=a+b+max(x,*max_element(s.begin(),s.end()));
        s.insert(0);
        while(!q.empty()){
            auto [back,node,step]=q.front();
            q.pop();
            if(node==x)
                return step;
            if( back == 0 && node-b >= 0 && node - b <= limit && s.find(node-b) == s.end()){
                s.insert(node-b);
                q.push({1,node-b,step+1});
            }
            if(s.find(node+a) == s.end() && node + a >= 0 && node+a <= limit){
                q.push({0,node+a,step+1});
                s.insert(node+a);
            }
           
        }
        return -1;
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        set<int> s(forbidden.begin(),forbidden.end());
        return bfs(s,a,b,x);
    }
};