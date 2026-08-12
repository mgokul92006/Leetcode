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
    void inorder(map<TreeNode*,TreeNode*>&mp,TreeNode* root){
        if(root==NULL)
        return;
        inorder(mp,root->left);
        if(root->left!=NULL)
            mp[root->left]=root;
        inorder(mp,root->right);
        if(root->right!=NULL)
            mp[root->right]=root;
    }
    TreeNode* inorder1(TreeNode* n,int s){
        if(n==NULL)
        return NULL;
        if(n->val==s)
        return n;
        TreeNode* l=inorder1(n->left,s);
        TreeNode* r=inorder1(n->right,s);
        if(l)
        return l;
        else
        return r;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mp;
        if(root->left)
        mp[root->left]=root;
        if(root->right)
        mp[root->right]=root;
        inorder(mp,root->left);
        inorder(mp,root->right);
        TreeNode* n=inorder1(root,start);
        queue<tuple<TreeNode*,int>>q;
        q.push({n,0});
        set<TreeNode*>s;
        s.insert(n);
        int maxi=0;
        while(!q.empty()){
            auto [node,m]=q.front();
            q.pop();
            if(node->left && s.find(node->left)==s.end()){
                q.push({node->left,m+1});
                s.insert(node->left);
                maxi=max(maxi,m+1);
            }
            if(node->right && s.find(node->right)==s.end()){
                q.push({node->right,m+1});
                s.insert(node->right);
                maxi=max(maxi,m+1);
            }
            TreeNode* p=mp[node];
            if(s.find(p)==s.end() && p!=NULL){
                q.push({p,m+1});
                s.insert(p);
                maxi=max(maxi,m+1);
            }
        }
        return maxi;
    }
};