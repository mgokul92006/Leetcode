class Solution {
public:
    bool check(int m,int days,vector<int>&weights){
        int c=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum=sum+weights[i];
            if(sum>m){
                sum=0;
                sum=weights[i];
                c++;
            }
        }
        return c<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=0;
        while(low<=high){
            int m=(low+high)/2;
            if(check(m,days,weights)){
                ans=m;
                high=m-1;
            }
            else
                low=m+1;
        }
        return ans;
    }
};