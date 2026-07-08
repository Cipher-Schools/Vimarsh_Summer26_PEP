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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head ;
        }
        ListNode* start = head ;
        ListNode* itr = head ;
        ListNode* prev = head ;
        int n = 0;
        while(itr){
            itr= itr->next ;
            n++ ;
        }
        k= k%n ;
        if(k==0){
            return head ;
        }
        int t = n-k ;
        itr = head ;
        while(t--){
            prev= itr ;
            itr= itr->next ;
        }
        prev->next= nullptr ;
        ListNode *head2 ;
        head2 = itr ;
        while(itr->next){
            itr = itr->next ;
        }
        itr->next= head ;
        return head2 ;
    }
};