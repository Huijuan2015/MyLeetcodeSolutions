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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* nodeA = headA;
        ListNode* nodeB = headB;
        int lenA = 1;
        int lenB = 1;
        while(nodeA->next){
            nodeA = nodeA->next;
            lenA++;
        }
        
        while(nodeB->next){
            nodeB = nodeB->next;
            lenB++;
        }
        if(nodeA != nodeB) return NULL;
        int diff = 0;
        
        if(lenA >= lenB){
            diff = lenA-lenB;
            while(diff>0){
                diff--;
                headA = headA->next;
            }
            
        }else{
            diff = lenB-lenA;
            while(diff>0){
                diff--;
                headB = headB->next;
            }
        }
        
        while(headA != headB){
                headA = headA->next;
                headB = headB->next;
            }
        return headA;
        
    }
};