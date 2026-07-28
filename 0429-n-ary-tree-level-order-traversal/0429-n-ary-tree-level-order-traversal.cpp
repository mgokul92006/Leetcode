/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void level(Node* root,vector<vector<int>>&ans){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<int>l;
            for(int i=0;i<s;i++){
                auto node=q.front();
                q.pop();
                for(auto k:node->children){
                    q.push(k);
                }
                l.push_back(node->val);
            }
            ans.push_back(l);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
        return {};
        vector<vector<int>>ans;
        level(root,ans);
        return ans;
    }
};