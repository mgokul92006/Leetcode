/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*>a1;
    vector<TreeNode*>b1;
    void path(TreeNode* root,TreeNode* q,vector<TreeNode*>&a){
        if(root==NULL)
        return;
        if(root==q){
            a.push_back(root);
            a1=a;
            return;
        }
        a.push_back(root);
        path(root->left,q,a);
        path(root->right,q,a);
        a.pop_back();
    }
    void path1(TreeNode* root,TreeNode* q,vector<TreeNode*>&c){
        if(root==NULL)
        return;
        if(root==q){
            c.push_back(root);
            b1=c;
            return;
        }
        c.push_back(root);
        path1(root->left,q,c);
        path1(root->right,q,c);
        c.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,c;
        path(root,p,a);
        path1(root,q,c);
        TreeNode* com;
        for(int i=0;i<min(a1.size(),b1.size());i++){
            if(a1[i]==b1[i]){
                com=a1[i];
            }
            else
            break;
        }
        return com;
    }
};