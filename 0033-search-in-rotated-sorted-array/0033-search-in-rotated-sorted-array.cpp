class Solution {
public:
    int bs(int l,int h,int tar,vector<int>&nums){
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==tar)
                return mid;
            else if(nums[mid]<tar)
                l=mid+1;
            else
                h=mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[l]<=nums[m]){
                if(target >= nums[l] && nums[m] >= target){
                    return bs(l,m,target,nums);
                }
                l=m+1;
            }
            else{
                if(target >= nums[m] && nums[h] >= target)
                return bs(m,h,target,nums);
                h=m-1;
            }
        }
        return -1;
    }
};