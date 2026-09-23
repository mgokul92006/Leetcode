class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        sum=sum-x;
        if(sum<0)
        return -1;
        int l=0,r=0;
        int sum1=0,maxi=0,flag=0;
        while(l<nums.size()){
            sum1=sum1+nums[l];
            while(sum1>sum){
                sum1=sum1-nums[r];
                r++;
            }
            if(sum1==sum){
                flag=1;
                maxi=max(maxi,l-r+1);
            }
            l++;
        }
        if(flag==0)
        return -1;
        return nums.size()-maxi;
    }
};