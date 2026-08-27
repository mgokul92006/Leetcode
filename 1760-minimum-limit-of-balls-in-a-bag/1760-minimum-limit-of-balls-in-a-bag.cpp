class Solution {
public:
    bool check(int m,vector<int>&nums,int maxi){
        unsigned long long c=0;
        for(int i=0;i<nums.size();i++){
            int cur=nums[i];
            if(cur>m && cur%m!=0){
                c=c+1+cur/m-1;
            }else if(cur>m){
                c=c+cur/m-1;
            }
        }
        return c<=maxi;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1,h=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(l<=h){
            int m=(h-l)/2+l;
            if(check(m,nums,maxOperations)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};