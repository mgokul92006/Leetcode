class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>ans;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>q;
        for(int i=0;i<nums1.size();i++){
            q.push({nums2[0]+nums1[i],i,0});
        }
        while(!q.empty()){
            auto [sum,i,j]=q.top();
            q.pop();
            ans.push_back({nums1[i],nums2[j]});
            if(k==ans.size())
            return ans;
            if(j+1<nums2.size()){
                q.push({nums2[j+1]+nums1[i],i,j+1});
            }
        }
        return ans;
    }
};