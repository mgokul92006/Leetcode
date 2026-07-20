class Solution {
public:
    bool check(int days,int mid,vector<int>&weights){
        int c=1,sum=0;
        for(int i=0;i<weights.size();i++){
            sum=sum+weights[i];
            if(weights[i]>mid)
            return false;
            if(sum>mid){
                c++;
                sum=0;
                sum=sum+weights[i];
            }
        }
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1,high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(days,mid,weights)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};