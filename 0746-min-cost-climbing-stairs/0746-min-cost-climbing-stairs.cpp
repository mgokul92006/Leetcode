class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int arr[cost.size()];
        arr[0]=cost[0];
        arr[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            arr[i]=min(cost[i]+arr[i-1],cost[i]+arr[i-2]);
        }
        return min(arr[cost.size()-2],arr[cost.size()-1]);
    }
};