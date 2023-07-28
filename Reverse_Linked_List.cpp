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
    ListNode* reverseList(ListNode* head) {
       if(head==NULL || head->next==NULL){return head;}
       ListNode *newhead = reverseList(head->next);
       ListNode *headnxt = head->next;
       headnxt->next=head;
       head->next=NULL;
       return newhead;
      /*  ListNode *nhead = NULL;
        while(head !=NULL)
        {
          ListNode *next=head->next;
          head->next=nhead;
          nhead=head;
          head=next;
        }
        return nhead;
        */
    }
};
