class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<pair<int,int>>v;
        for(int i=0;i<meetings.size();i++){
            v.push_back({meetings[i][0],1});
            v.push_back({meetings[i][1],-1});
        }
        sort(v.begin(),v.end(),[] (auto a,auto b){
            if(a.first==b.first)
            return a.second>b.second;
            return a.first<b.first;
        });
        int sum=0,f=0;
        for(int i=0;i<v.size();i++){
            if(sum==0){
                f=v[i].first;
            }
            sum=sum+v[i].second;
            if(sum==0){
                days=days-(v[i].first-f+1);
            }
        }
        return days;
    }
};