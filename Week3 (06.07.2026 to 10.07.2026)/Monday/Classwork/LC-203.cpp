/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* top = new ListNode(-1) ; 
        top->next = head ;
        ListNode *curr= top ;
        while(curr->next != nullptr){
            if(curr->next->val == val){
                curr->next = curr->next->next ;
            } else {
                curr = curr->next ;
            }
        }
        return top->next ;
    }
};