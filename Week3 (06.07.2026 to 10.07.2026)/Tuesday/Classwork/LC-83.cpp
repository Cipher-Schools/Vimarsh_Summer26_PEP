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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *itr = head ;
        ListNode *prev = head ;
        while(itr){
            if(prev->val == itr->val){
                prev->next = itr->next ;
            } else {
                prev = itr ;
            }
            itr= itr->next ;

        }
        return head ;
    }
};