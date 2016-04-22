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
    ListNode* swapPairs(ListNode* head) {
        //swap(pre->next,cur->next)
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode * pre = dummy;
        ListNode * cur = head;
        while(pre->next && cur->next){
            //swap
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = cur;
            //update
            pre = cur;
            cur = pre->next;
        }
        return dummy->next;
    }
};