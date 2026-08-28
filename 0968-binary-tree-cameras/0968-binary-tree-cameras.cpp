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
    int c=0;
    int post(TreeNode* root){
        if(root==NULL)
        return 0;
        int a=post(root->left);
        int b=post(root->right);
        if(a==0 && b==0)
        return 2;
        if(a==2 || b==2){
            c++;
            return 1;
        }
        if(a==1 || b==1){
        return 0;
        }
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if(root->left==NULL && root->right==NULL)
        return 1;
        if(post(root)==2)
        c++;
        return c;
    }
};