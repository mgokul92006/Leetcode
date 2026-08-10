class Solution {
public:
    long long path(map<int,vector<int>>&mp,vector<int>&parent,vector<int>&nums){
        queue<pair<long long,long long>>q;
        q.push({0,1});
        vector<long long>ans(parent.size());
        long long maxi=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [no,dp]=q.front();
                ans[no]=dp;
                maxi=max(maxi,dp);
                q.pop();
                for(auto k:mp[no]){
                    q.push({k,dp+1});
                }
            }
        }
        long long sum1=0;
        for(int i=0;i<nums.size();i++){
            sum1=sum1+(long long)(nums[i]*(maxi-ans[i]+1));
        }
        return sum1;
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        map<int,vector<int>>mp;
        int j=1;
        for(int i=1;i<parent.size();i++){
            mp[parent[i]].push_back(j);
            j++;
        }
        return path(mp,parent,nums);
    }
};