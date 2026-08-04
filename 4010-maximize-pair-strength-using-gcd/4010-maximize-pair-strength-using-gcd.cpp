class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long maxi=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                long long val=1ll*nums[i]*nums[j];
                long long g=1ll*gcd(nums[i],nums[j])*gcd(nums[i],nums[j]);
                val=val/g;
                if(val>maxi)
                maxi=val;
            }
        }
        return maxi;
    }
};