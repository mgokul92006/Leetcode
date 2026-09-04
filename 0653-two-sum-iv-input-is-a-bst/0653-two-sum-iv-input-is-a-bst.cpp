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
    bool flag=0;
    void post(TreeNode* root,int k,set<int>&s){
        if(root==NULL)
        return;
        post(root->left,k,s);
        if(s.find(k-root->val)!=s.end()){
            flag=1;
            return;
        }
        else
            s.insert(root->val);
        post(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>s;
        post(root,k,s);
        return flag;
    }
};