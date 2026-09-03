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
    TreeNode* constr(vector<int>&nums,int i,int j){
        if(i>j)
        return NULL;
        int m=(i+j)/2;
        TreeNode* n=new TreeNode(nums[m]);
        n->left=constr(nums,i,m-1);
        n->right=constr(nums,m+1,j);
        return n;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constr(nums,0,nums.size()-1);
    }
};