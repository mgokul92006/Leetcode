class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        int arr[nums.size()-1];
        int arr1[nums.size()];
        arr[0]=nums[0];
        arr1[0]=0;
        arr[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size()-1;i++){
            arr[i]=max(arr[i-1],nums[i]+arr[i-2]);
        }
        arr1[1]=nums[1];
        for(int i=2;i<nums.size();i++){
            arr1[i]=max(arr1[i-1],nums[i]+arr1[i-2]);
        }
        return max(arr[nums.size()-2],arr1[nums.size()-1]);
    }
};