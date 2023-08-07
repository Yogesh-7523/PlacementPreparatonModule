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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int cnt=0;
        while(curr!=NULL && cnt != k){
           curr=curr->next;
           cnt++;
        }
        if(cnt==k){
            curr = reverseKGroup(curr,k);
        
        while(cnt>0){
            ListNode* tmp = head->next;
            head->next=curr;
            curr=head;
            head=tmp;
            cnt--;
        }
        head=curr;
        }
        return head;
    }
};
