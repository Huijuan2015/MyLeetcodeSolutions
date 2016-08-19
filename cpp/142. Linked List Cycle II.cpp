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
    ListNode *detectCycle(ListNode *head) {
       // if(!head || !head->next) return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        //bool hasCycle = false;
        while(fast && fast->next){//注意判断条件
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    fast = fast->next;
                    slow = slow->next;
                    
                }
                return slow;
            }
        }
        return NULL;
    }
};




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
    ListNode *detectCycle(ListNode *head) {
        //if(!head || !head->next) return;
        
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasCycle = false;
        while(hasCycle == false && fast && fast->next){//注意判断条件
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                slow = head;
                hasCycle = true;
            }
        }
        
        while(hasCycle == true && fast != slow){
            fast = fast->next;
            slow = slow->next;
            
        }
        if(hasCycle) return slow;
        return NULL;
    }
};