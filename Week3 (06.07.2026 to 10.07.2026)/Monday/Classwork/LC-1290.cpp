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
    int getDecimalValue(ListNode* head) {
        
        ListNode *itr = head ;
        int num= 0 ;
        
        while(itr){
            num++ ;
            itr= itr->next ;
        }

        itr= head ;

        int ans = 0 ;
        
        num-- ;

        while(itr){
            ans = ans + ((itr->val) * pow(2, num)) ;
            num-- ;
            itr= itr->next ;
        }

        return ans ;
    }
};