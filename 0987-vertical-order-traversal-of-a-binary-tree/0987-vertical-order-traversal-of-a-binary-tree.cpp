/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [n,l,v]=q.front();
                q.pop();
                m[v][l].insert(n->val);
                if(n->left!=NULL){
                    q.push({n->left,l+1,v-1});
                }
                if(n->right!=NULL){
                    q.push({n->right,l+1,v+1});
                }
            }
        }
        vector<vector<int>>ans;
        for(auto [key1,in]:m){
            vector<int>ans1;
            for(auto [key2,ms]:in){
                for(auto i:ms){
                    ans1.push_back(i);
                }
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};