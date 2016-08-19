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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        while(pre->next && pre->next->next){
            if(pre->next->val == val){
                pre->next = pre->next->next;
            }else{
                pre = pre->next;
            }
        }
        if(!pre->next->next && pre->next->val == val){
            pre->next = NULL;
        }
        return dummy->next;
    }
};