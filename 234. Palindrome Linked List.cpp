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
    bool isPalindrome(ListNode* head) {
        //如果链表为空或者仅有一个元素那么肯定是回文链表 
        if(head == NULL || head->next == NULL) return true;
        //快慢指针法，寻找链表中心 
        ListNode * slow = head;
        ListNode * fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //翻转后半段比较
        slow->next = reverseList(slow->next);
        slow = slow->next;
        
        while(slow!=NULL){
            if(head->val != slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode * reverseList(ListNode * head){
        ListNode * pre = NULL;
        ListNode * next = NULL;
        
        while(head != NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};