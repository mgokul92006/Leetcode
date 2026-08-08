/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void recur(map<TreeNode*,TreeNode*>&mp,TreeNode* root){
        if(root==NULL)
        return;
        recur(mp,root->left);
        if(root->left!=NULL){
            mp[root->left]=root;
        }
        recur(mp,root->right);
        if(root->right!=NULL){
            mp[root->right]=root;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        if(root->left)
        mp[root->left]=root;
        if(root->right)
        mp[root->right]=root;
        recur(mp,root->left);
        recur(mp,root->right);
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        vector<int>ans;
        map<TreeNode*,int>a;
        a[target]=1;
        while(!q.empty()){
            int s1=q.size();
            for(int i=0;i<s1;i++){
                auto [node,s]=q.front();
                q.pop();
                if(s==k)
                ans.push_back(node->val);
                if(node->left && a[node->left]==0){
                    a[node->left]=1;
                    q.push({node->left,s+1});
                }
                if(node->right && a[node->right]==0){
                    a[node->right]=1;
                    q.push({node->right,s+1});
                }
                TreeNode* j=mp[node];
                if(a[j]==0 && j!=NULL){
                    q.push({j,s+1});
                    a[j]=1;
                }
            }
            cout<<endl;
        }
        return ans;
    }
};