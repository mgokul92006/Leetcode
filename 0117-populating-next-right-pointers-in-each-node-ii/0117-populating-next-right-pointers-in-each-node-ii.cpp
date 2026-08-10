/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void path(Node* root){
        if(root==NULL)
        return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            Node* temp=NULL;
            for(int i=0;i<s;i++){
                Node* n=q.front();
                q.pop();
                if(n->left){
                    q.push(n->left);
                }
                if(n->right){
                    q.push(n->right);
                }
                if(i!=s-1)
                    n->next=q.front();
            }
        }
    }
    Node* connect(Node* root) {
        path(root);
        return root;
    }
};