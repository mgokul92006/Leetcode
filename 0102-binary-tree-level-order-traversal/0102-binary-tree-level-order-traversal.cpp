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
    vector<vector<int>>ans;
    void level(TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>ans1;
            for(int i=0;i<s;i++){
                if(q.front()!=NULL && q.front()->left)
                    q.push(q.front()->left);
                if(q.front()!=NULL && q.front()->right)
                    q.push(q.front()->right);
                if(q.front())
                ans1.push_back(q.front()->val);
                q.pop();
            }
            ans.push_back(ans1);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        level(root);
        return ans;
    }
};