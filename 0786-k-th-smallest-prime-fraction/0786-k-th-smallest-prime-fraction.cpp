class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double,pair<int,int>>>ans;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans.push_back({arr[i]*1.0/arr[j]*10,{arr[i],arr[j]}});
            }
        }
        sort(ans.begin(),ans.end());
        int a=ans[k-1].second.first;
        int b=ans[k-1].second.second;
        return {a,b};
    }
};