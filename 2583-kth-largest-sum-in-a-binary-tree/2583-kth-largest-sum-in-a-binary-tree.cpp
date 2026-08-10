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
    long long path(TreeNode* root,int k){
        if(root==NULL)
        return 0;
        priority_queue<long long,vector<long long>,greater<long long>>q;
        queue<TreeNode*>q1;
        q1.push(root);
        while(!q1.empty()){
            int s=q1.size();
            long long sum = 0;
            for(int i=0;i<s;i++){
                auto node=q1.front();
                q1.pop();
                sum = sum +node->val;
                if(node->left){
                    q1.push(node->left);
                }
                if(node->right)
                    q1.push(node->right);
            }
            if(k>q.size()){
                q.push(sum);
            }
            else if(q.top()<=sum){
                q.push(sum);
                q.pop();
            }
        }
        if(q.size()<k)
        return -1;
        return q.top();
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        return path(root,k);
    }
};