class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=1;
        if(nums.empty())
        return 0;
        sort(nums.begin(),nums.end());
        int maxi=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                continue;
            }
            else if(nums[i]==nums[i+1]-1)
            {
                count++;
                maxi=max(count,maxi);
            }
            else{
            maxi=max(count,maxi);
            count=1;
            }
        }
        return maxi;
    }
};