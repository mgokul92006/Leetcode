class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
        for(auto i:nums){
            int pos=lower_bound(res.begin(),res.end(),i)-res.begin();
            if(pos==res.size())
            res.push_back(i);
            else
            res[pos]=i;
        }
        return res.size();
    }
};