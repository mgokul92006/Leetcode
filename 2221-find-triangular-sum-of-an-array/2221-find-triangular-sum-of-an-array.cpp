class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>ans;
        while(nums.size()>1){
            for(int j=0;j<nums.size()-1;j++){
                ans.push_back((nums[j]+nums[j+1])%10);
            }
            nums=ans;
            ans.clear();
        }
        return nums[0];
    }
};