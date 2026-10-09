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
    int count(TreeNode* root,bool flag){
        if(root==NULL)
        return 1;
        int c=1;
        if(flag){
            while(root->right){
                c++;
                root=root->right;
            }
            return c;
        }
        else{
            while(root->left){
                c++;
                root=root->left;
            }
            return c;
        }
        return 0;
    }
    int calculate(TreeNode* root){
        if(root==NULL)
        return 0;
        int l=count(root,0);
        int r=count(root,1);
        cout<<l<<" "<<r<<endl;
        if(l==r)
            return (1<<l)-1;
        return 1+calculate(root->left)+calculate(root->right);
    }
    int countNodes(TreeNode* root) {
        return calculate(root);
    }
};