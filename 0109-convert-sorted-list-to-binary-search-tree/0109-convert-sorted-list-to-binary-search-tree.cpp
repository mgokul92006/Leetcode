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
    ListNode* mid(ListNode* head,ListNode* end){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=end && fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    TreeNode* convert(ListNode* head,ListNode* end){
        if(head==NULL || head==end)
        return NULL;
        ListNode* l=mid(head,end);
        TreeNode* n=new TreeNode(l->val);
        n->left=convert(head,l);
        n->right=convert(l->next,end);
        return n;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return convert(head,NULL);
    }
};