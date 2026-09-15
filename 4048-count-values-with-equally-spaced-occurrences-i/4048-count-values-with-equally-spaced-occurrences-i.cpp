class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]].size()==3){
                vector<int>ans;
                ans=mp[nums[i]];
                if(ans[1]-ans[0] == ans[2]-ans[1])
                c++;
                mp.erase(nums[i]);
            }
        }
        return c;
    }
};