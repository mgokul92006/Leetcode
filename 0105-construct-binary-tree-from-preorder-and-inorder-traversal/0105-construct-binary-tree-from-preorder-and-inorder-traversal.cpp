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
    TreeNode* construct(vector<int>&preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd,map<int,int>&a){
        if(preStart>preEnd || inStart>inEnd)
        return NULL;
        TreeNode* n=new TreeNode(preorder[preStart]);
        int inroot=a[n->val];
        int numsLeft=inroot-inStart;
        n->left=construct(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inroot-1,a);
        n->right=construct(preorder,preStart+numsLeft+1,preEnd,inorder,inroot+1,inEnd,a);
        return n;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>a;
        for(int i=0;i<preorder.size();i++)
            a[inorder[i]]=i;
        return construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,a);
    }
};