class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>res;
        for(auto i:nums){
            int pos=lower_bound(res.begin(),res.end(),i)-res.begin();
            if(pos==res.size())
                res.push_back(i);
            else
                res[pos]=i;
            if(res.size()==3)
                return 1;
        }
        return 0;
    }
};