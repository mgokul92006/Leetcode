class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
                mp[s[i]].second=i;
            }
            else
                mp[s[i]].second=i;
        }
        vector<int>ans;
        for(int i=0;i<s.size();){
            int end=mp[s[i]].second;
            int cur=i;
            while(i<=end){
                if(s[cur]!=s[i]){
                    end=max(end,mp[s[i]].second);
                }
                i++;
            }
            ans.push_back(i-cur);
        }
        return ans;
    }
};