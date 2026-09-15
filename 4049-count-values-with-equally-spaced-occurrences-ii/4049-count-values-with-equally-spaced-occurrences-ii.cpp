class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]].push_back(i);
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]].size()>=3){
                vector<int>ans;
                ans=mp[nums[i]];
                int old=ans[1]-ans[0];
                bool flag=0;
                for(int i=2;i<ans.size();i++){
                    if(old!=ans[i]-ans[i-1]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                c++;
                mp.erase(nums[i]);
            }
        }
        return c;
    }
};