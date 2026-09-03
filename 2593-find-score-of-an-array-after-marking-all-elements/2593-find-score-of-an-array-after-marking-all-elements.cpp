class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<int> vis(nums.size(), 0);
        vector<pair<int, int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp.push_back({nums[i], i});
        }
        sort(mp.begin(), mp.end());
        long long score = 0;
        for (int i = 0; i < mp.size(); i++) {
            int ind1 = mp[i].second;
            if (vis[ind1] == 0) {
                vis[ind1] = 1;
                score = score + nums[ind1];
                int ind = ind1;
                if (ind - 1 >= 0)
                    vis[ind - 1] = 1;
                if (ind + 1 < nums.size())
                    vis[ind + 1] = 1;
            }
        }
        return score;
    }
};