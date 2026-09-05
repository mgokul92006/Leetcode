class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n+1,0);
        for(auto i:bookings){
            arr[i[0]-1]=arr[i[0]-1]+i[2];
            if(i[1]<n)
                arr[i[1]]=arr[i[1]]-i[2];
        }
        vector<int>ans(n,0);
        ans[0]=arr[0];
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+arr[i];
        }
        return ans;
    }
};