class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>k(n+1,0);
        for(auto a:bookings){
            int f=a[0];
            int l=a[1];
            int v=a[2];
            k[f-1]+=v;
            if(l<n){
                k[l]-=v;
            }
        }
        vector<int>ans(n,0);
        ans[0]=k[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+k[i];
        }
        return ans;
    }
};