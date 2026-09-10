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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int i,int j,int l,int k,unordered_map<int,int>&mp){
        if(i>j || l>k)
        return NULL;
        TreeNode* n=new TreeNode(postorder[k]);
        int ind=mp[postorder[k]];
        int count=j-ind;
        n->left=build(inorder,postorder,i,ind-1,l,k-count-1,mp);
        n->right=build(inorder,postorder,ind+1,j,k-count,k-1,mp);
        return n;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,mp);
    }
};