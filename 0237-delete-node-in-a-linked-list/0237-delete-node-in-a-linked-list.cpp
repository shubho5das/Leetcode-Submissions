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
    void deleteNode(ListNode* current){
        ListNode *nxt = (current->next);        
        current->val = nxt->val;
        current->next = nxt->next;
    }
};