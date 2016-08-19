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
    ListNode* deleteDuplicates(ListNode* head) {
         if(!head) return NULL;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head, *next = head->next;
        bool flag = false;
        
        while(next){
            if(next->val == cur->val){
                flag = true;
                next = next->next;
            }else{
                if(flag){
                    pre->next = next;
                    cur = next;
                    
                }else{
                    pre = pre->next;
                    cur = cur->next;
                    
                }
                next = next->next;
                flag = false;
            }
        }
       if(flag) pre->next = next;//end
       return dummy->next;
    }
    
};