class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            if(nums[i]==0)
            nums[i]=-1;
        unordered_map<int,int>mp;
        int sum=0,maxi=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            if(mp.find(sum)!=mp.end())
                maxi=max(maxi,i-mp[sum]);
            else
                mp[sum]=i;
        }
        return maxi;
    }
};