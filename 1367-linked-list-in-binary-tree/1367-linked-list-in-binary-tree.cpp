/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool flag=0;
    bool validate(TreeNode* root,ListNode* temp1){
        if(temp1==NULL){
            flag=1;
            return 1;
        }
        if(root==NULL)
        return 0;
        int left=0,right=0;
        if(root->left && root->left->val==temp1->val)
        {
            left=left || validate(root->left,temp1->next);
        }
        if(root->right && root->right->val==temp1->val){
            right=right || validate(root->right,temp1->next);
        }
        return left || right;
        
    }
    void inorder(TreeNode* root,ListNode* head){
        if(root==NULL)
        return;
        if(root->val==head->val){
            ListNode* temp1=head;
            validate(root,temp1->next);
            if(flag)
            return;
        }
        inorder(root->left,head);
        inorder(root->right,head);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        TreeNode* temp=root;
        inorder(temp,head);
        return flag;
    }
};