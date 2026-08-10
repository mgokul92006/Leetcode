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
class FindElements {
public:
    TreeNode* n;
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [node,ind]=q.front();
                q.pop();
                node->val=ind;
                if(node->left)
                    q.push({node->left,ind*2+1});
                if(node->right)
                    q.push({node->right,ind*2+2});
            }
        }
        n=root;
    }
    bool find1(TreeNode* root,int target){
        if(root==NULL)
        return 0;
        if(root->val==target)
        return true;
        return find1(root->right,target) || find1(root->left,target);
    }
    bool find(int target) {
        TreeNode* temp=n;
        return find1(n,target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */