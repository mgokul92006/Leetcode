class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=0,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi)
                c++;
            else
            {
                ans=max(ans,c);
                c=0;
            }
        }
        return max(c,ans);
    }
};