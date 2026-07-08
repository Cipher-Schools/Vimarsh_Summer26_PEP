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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head= new ListNode() ;
        ListNode* itr= head ;
        ListNode* prev= new ListNode() ;
        itr->val= 0;
        int carry= 0;
        while(l1!= NULL && l2!= NULL){
            itr->val= (l1->val) + (l2->val) + carry ;
            itr->next= new ListNode() ;
            carry= (itr->val)/10 ;
            itr->val= (itr->val)%10 ;
            l1 = l1->next  ;
            l2 = l2->next  ;
            prev= itr;
            itr= itr->next ;
        }
        while(l1!=NULL){
            itr->val= (l1->val) + carry ;
            itr->next= new ListNode() ;
            carry= (itr->val)/10 ;
            itr->val= (itr->val)%10 ;
            l1 = l1->next  ;
            prev= itr;
            itr= itr->next ;
        }
        while(l2!=NULL){
            itr->val= (l2->val) + carry ;
            itr->next= new ListNode() ;
            carry= (itr->val)/10 ;
            itr->val= (itr->val)%10 ;
            l2 = l2->next  ;
            prev= itr ;
            itr= itr->next ;
        }
        itr->val+= carry ;
        if(itr->val==0){
            prev->next=NULL ;
        }
        return head ;
    }
};