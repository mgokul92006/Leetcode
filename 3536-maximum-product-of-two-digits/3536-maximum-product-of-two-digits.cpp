class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n){
            ans.push_back(n%10);
            n=n/10;
        }
        sort(ans.rbegin(),ans.rend());
        return ans[0]*ans[1];
    }
};