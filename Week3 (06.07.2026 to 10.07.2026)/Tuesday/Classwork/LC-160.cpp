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
        ListNode *itr1 = headA ;
        ListNode *itr2 = headB ;
        bool AptrChange = false ;
        bool BptrChange = false ;
        while(itr1 && itr2){
            if(itr1 == itr2 ){
                return itr1 ;
            }
            itr1 = itr1->next ;
            itr2 = itr2->next ;
            
            if((itr1 == nullptr) && !AptrChange){
                itr1= headB ;
                AptrChange = true ;
            }
            if((itr2 == nullptr) && !BptrChange){
                itr2 = headA ;
                BptrChange = true ;
            }
        }
        return nullptr ;
    }
};