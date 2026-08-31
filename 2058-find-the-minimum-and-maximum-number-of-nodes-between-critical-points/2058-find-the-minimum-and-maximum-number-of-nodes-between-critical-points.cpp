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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL)
        return {-1,-1};
        ListNode* temp=head->next;
        ListNode* prev=head;
        int c=2;
        vector<int>ans;
        while(temp->next!=NULL){
            if(prev->val<temp->val && temp->val>temp->next->val)
                ans.push_back(c);
            else if(prev->val>temp->val && temp->val<temp->next->val)
                ans.push_back(c);
            c++;
            prev=temp;
            temp=temp->next;
        }
        if(ans.size()==0 || ans.size()==1)
        return {-1,-1};
        int maxi=ans[ans.size()-1]-ans[0],mini=INT_MAX;
        for(int i=1;i<ans.size();i++){
            mini=min(mini,ans[i]-ans[i-1]);
        }
        return {mini,maxi};
    }
};