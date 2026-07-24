class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return n==nums.size()?-1:nums[n]==target?n:-1;
    }
};