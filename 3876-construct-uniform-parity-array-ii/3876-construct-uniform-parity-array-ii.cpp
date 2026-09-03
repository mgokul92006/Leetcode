class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int c=0,c1=0;
        int mini=INT_MAX;
        for(auto i:nums1){
            if(i%2==0)
                c++;
            else
                c1++;
            if(mini>i)
                mini=i;
        }
        if(c==nums1.size() || c1==nums1.size())
        return 1;
        vector<int>ans(nums1.size());
        if(mini!=nums1[0] && nums1[0]%2==0)
            ans[0]=nums1[0]-mini;
        else
            ans[0]=nums1[0];
        for(int i=1;i<nums1.size();i++){
            if(nums1[i]%2==1)
                ans[i]=nums1[i];
            else
                ans[i]=nums1[i]-mini;
        }
        for(int i=0;i<nums1.size()-1;i++){
            if(ans[i]%2!=ans[i+1]%2)
            return 0;
        }
        return 1;
    }
};