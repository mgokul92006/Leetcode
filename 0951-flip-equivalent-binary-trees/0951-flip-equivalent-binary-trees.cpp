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
    bool flip(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)
        return 1;
        if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL))
        return 0;
        if(root1->val!=root2->val)
        return 0;
        int left1=0,right1=0,left2=0,right2=0;
        if(root1->left)
        left1=root1->left->val;
        if(root1->right)
        right1=root1->right->val;
        if(root2->left)
        left2=root2->left->val;
        if(root2->right)
        right2=root2->right->val;
        bool a = false, b = false;
        if((left1==left2 && right1==right2) ){
            a = flip(root1->left,root2->left) && flip(root1->right,root2->right);
        }
        else if(left1==right2 && left2==right1){
            swap(root1->left,root1->right);
            b = flip(root1->left,root2->left) && flip(root1->right,root2->right);
        }
        return a || b;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return flip(root1,root2);
    }
};