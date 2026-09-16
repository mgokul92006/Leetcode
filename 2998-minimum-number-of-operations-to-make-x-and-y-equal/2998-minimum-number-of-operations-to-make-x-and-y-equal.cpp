class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>>q;
        q.push({0,x});
        set<int>s;
        s.insert(x);
        while(!q.empty()){
            int st=q.front().first;
            int num=q.front().second;
            q.pop();
            cout<<num<<" ";
            if(num==y)
            return st;
            if(num%11==0 && s.find(num/11)==s.end()){
                s.insert(num/11);
                q.push({st+1,num/11});
            }
            if(num%5==0 && s.find(num/5)==s.end()){
                s.insert(num/5);
                q.push({st+1,num/5});
            }
            if(num-1>0 && s.find(num-1)==s.end()){
                q.push({st+1,num-1});
                s.insert(num-1);
            }
            if(s.find(num+1)==s.end()){
                s.insert(num+1);
                q.push({st+1,num+1});
            }
        }
        return 0;
    }
};