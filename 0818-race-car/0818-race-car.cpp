class Solution {
public:
    int racecar(int target) {
        queue<tuple<long long,long long,long long>>q;
        q.push({0,0,1});
        set<pair<long long,long long>>s;
        s.insert({0,1});
        while(!q.empty()){
            auto [step,pos,speed]=q.front();
            q.pop();
            if(pos==target)
            return step;
            if(pos+speed<=target*2 &&s.find({pos+speed,speed*2})==s.end()){
                q.push({step+1,pos+speed,speed*2});
                s.insert({pos+speed,speed*2});
            }
            if(speed>0 && s.find({pos,-1})==s.end()){
                q.push({step+1,pos,-1});
                s.insert({pos,-1});
            }
            if(speed<0 && s.find({pos,1})==s.end()){
                q.push({step+1,pos,1});
                s.insert({pos,1});
            }
        }
        return -1;
    }
};