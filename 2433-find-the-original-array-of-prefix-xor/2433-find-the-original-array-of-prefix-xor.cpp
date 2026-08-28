class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans(pref.size());
        ans[0]=pref[0];
        int temp=pref[0];
        for(int i=1;i<pref.size();i++){
            ans[i]=pref[i]^temp;
            temp=temp^ans[i];
        }
        return ans;
    }
};