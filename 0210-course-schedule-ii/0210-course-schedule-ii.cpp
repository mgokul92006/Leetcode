class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ind(numCourses, 0);
        vector<vector<int>> res(numCourses);
        for (auto i : prerequisites) {
            res[i[0]].push_back(i[1]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            for (auto j : res[i]) {
                ind[j]++;
            }
        }
        vector<int>ans;
        for (int i = 0; i < ind.size(); i++) {
            if (ind[i] == 0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto k : res[i]) {
                ind[k]--;
                if (ind[k] == 0){
                    q.push(k);
                    ans.push_back(k);
                }
            }
        }
        for(int i=0;i<ind.size();i++){
            if(ind[i]!=0)
            return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
