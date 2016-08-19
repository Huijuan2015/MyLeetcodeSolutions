/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        
        ListNode* mid = findMid(head);
        TreeNode* root = new TreeNode(mid->val);
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* preslow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                preslow = slow;
                slow = slow->next;
            }
        }
        //切断链表
        preslow->next = NULL;
        return slow;
    }
};