class Solution {
public:
    int search1(int tar,vector<int>&nums){
        int l = 0 , h = nums.size() - 1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m] <= tar){
                l=m+1;
            }
            else
                h=m-1;
        }
        return h;
    }
    int search(int tar,vector<int>&nums){
        int l = 0 , h = nums.size() - 1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]>=tar){
                h=m-1;
            }
            else
                l=m+1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = search(target,nums) , high = search1(target,nums);
        if( nums.size() == lower || nums[lower]!=target)
            return{-1,-1};
        return {lower,high};
    }
};