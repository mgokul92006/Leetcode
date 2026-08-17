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
    TreeNode* path(vector<int>&nums,int i,int j){
        if(i>j)
        return NULL;
        int maxi=-1,ind=-1;
        for(int m=i;m<=j;m++){
            if(maxi<nums[m])
            {
                maxi=nums[m];
                ind=m;
            }
        }
        TreeNode* n=new TreeNode(maxi);
        n->left=path(nums,i,ind-1);
        n->right=path(nums,ind+1,j);
        return n;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return path(nums,0,nums.size()-1);
    }
};