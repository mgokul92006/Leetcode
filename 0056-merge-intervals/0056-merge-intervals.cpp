class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>>p;
        for(int i=0;i<intervals.size();i++){
            p.push_back({intervals[i][0],1});
            p.push_back({intervals[i][1],-1});
        }
        sort(p.begin(),p.end(),[](auto a,auto b){
            if(a.first==b.first)
                return a.second>b.second;
            return a.first<b.first;
        });
        vector<vector<int>>ans;
        int sum=0;
        bool flag=0;
        int old=-1;
        for(int i=0;i<p.size();i++){
            if(flag==0){
                old=p[i].first;
                flag=1;
            }
            sum=sum+p[i].second;
            if(sum==0){
                ans.push_back({old,p[i].first});
                flag=0;
            }
        }
        return ans;
    }
};