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
    TreeNode* compute(vector<int>&arr,int i,int j){
        if(i>j)
        return NULL;
        int m=(i+j)/2;
        TreeNode* n=new TreeNode(arr[m]);
        n->left=compute(arr,i,m-1);
        n->right=compute(arr,m+1,j);
        return n;
    }
    void inorder(TreeNode* root,vector<int>&arr){
        if(root==NULL)
        return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);
        return compute(arr,0,arr.size()-1);
    }
};