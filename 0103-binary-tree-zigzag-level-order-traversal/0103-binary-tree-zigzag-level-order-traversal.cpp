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
    vector<vector<int>>ans;
    void level(TreeNode* root){
        if(root==NULL)
        return;
        queue<TreeNode*>q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int s=q.size();
            vector<int>ans1;
            for(int i=0;i<s;i++){
                if(q.front() && q.front()->left)
                    q.push(q.front()->left);
                if(q.front() && q.front()->right)
                    q.push(q.front()->right);
                ans1.push_back(q.front()->val);
                q.pop();
            }
            if(c%2==1)
                reverse(ans1.begin(),ans1.end());
            ans.push_back(ans1);
            c++;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        level(root);
        return ans;
    }
};