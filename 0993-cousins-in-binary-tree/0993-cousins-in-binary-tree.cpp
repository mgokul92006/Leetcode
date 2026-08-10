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
    bool path(TreeNode* root,int x,int y){
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,-1});
        int val1=0,val2=0,dep1=0,dep2=0;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [node,s,p]=q.front();
                q.pop();
                if(node->left)
                    q.push({node->left,s+1,node->val});
                if(node->right)
                    q.push({node->right,s+1,node->val});
                if(node->val==x){
                    val1=p;
                    dep1=s;
                }
                if(node->val==y){
                    val2=p;
                    dep2=s;
                }
            }
        }
        if(dep1==dep2 && val1!=val2)
        return true;
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        return path(root,x,y);
    }
};