class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN,ind1=-1,ind2=-1;
        if(nums.size()==1)
        return 1;
        for(int i=0;i<nums.size();i++){
            if(mini>nums[i]){
                mini=nums[i];
                ind1=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                ind2=i;
            }
        }
        
        int small=INT_MAX,c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==mini || nums[i]==maxi)
            c++;
            if(c==2){
                small=min(small,i+1);
                break;
            }
        }
        int s=nums.size();
        c=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==mini || nums[i]==maxi)
            c++;
            if(c==2){
                small=min(small,s-i);
            }
        }
        c=0;
        int p=0,q=nums.size()-1;
        p=min(ind1,ind2);
        q=min(s-ind1,s-ind2);
        small=min(small,p+q+1);
        return small;
    }
};