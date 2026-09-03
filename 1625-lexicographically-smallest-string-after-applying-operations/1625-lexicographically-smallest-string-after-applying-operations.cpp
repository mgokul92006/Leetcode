class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string>vis;
        vis.insert(s);
        queue<string>q;
        q.push(s);
        while(!q.empty()){
            string n=q.front();
            q.pop();
            string temp=n;
            for(int i=0;i<n.size();i++){
                if(i%2==1){
                    int k=n[i]-'0';
                    k=k+a;
                    k=k%10;
                    n[i]=k+'0';
                }
            }
            if(vis.find(n)==vis.end()){
                vis.insert(n);
                q.push(n);
            }
            int size=b%temp.size();
            reverse(temp.begin(),temp.end());
            reverse(temp.begin(),temp.begin()+size);
            reverse(temp.begin()+size,temp.end());
            if(vis.find(temp)==vis.end()){
                vis.insert(temp);
                q.push(temp);
            }
        }
        return *vis.begin();
    }
};