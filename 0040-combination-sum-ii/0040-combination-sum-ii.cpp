class Solution {
public:
    void sum(vector<vector<int>>&ans,vector<int>temp,vector<int>&candidates,int target,int i){
        if(target<0)
        return;
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(j>i && candidates[j]==candidates[j-1])
            continue;
            temp.push_back(candidates[j]);
            sum(ans,temp,candidates,target-candidates[j],j+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        sum(ans,temp,candidates,target,0);
        return ans;
    }
};