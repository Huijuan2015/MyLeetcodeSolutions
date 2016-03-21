/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //fast 先走n步
        if(!head) return nullptr;
         ListNode dummy(-1);
         dummy.next = head;
         
         ListNode * fast = &dummy;
         ListNode * slow = &dummy;
         
         for(int i = 0; i < n; ++i){
             fast = fast->next;
         }
         
         while(fast->next){
             fast = fast->next;
             slow = slow->next;
         }
         
         ListNode* target = slow->next;//better to have
         slow->next = slow->next->next;
         
         delete target;//better to have
         return dummy.next;
    }
};