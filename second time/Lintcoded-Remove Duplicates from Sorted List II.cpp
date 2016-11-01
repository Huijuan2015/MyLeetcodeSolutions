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
        ListNode* pre = dummy, * cur = head, * next = head->next;
        bool flag = false;//if cur is duplicated with node already deleted
        while(next){
            if(next->val == cur->val){
                next = next->next;
                flag = true;
            }else{
                if(flag){//is duplicated, should be deleted
                    cur = next;
                    pre->next = next;
                }else{
                    pre = pre->next;
                    cur = cur->next;
                }
                flag = false;
                next = next->next;
            }
        }
        if(flag) pre->next = next;//NULL
        return dummy->next;
    }
};