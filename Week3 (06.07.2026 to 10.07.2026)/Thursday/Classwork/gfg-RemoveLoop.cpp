class Solution {
public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;
        
        Node* slow = head;
        Node* fast = head;
        
        // Step 1: Detect Loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        // If no loop exists
        if (slow != fast) return;
        
        // Step 2: Find the starting node of the loop
        slow = head;
        if (slow == fast) { // Special case: Loop starts at head
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL; // Break loop
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL; // Break loop
        }
    }
};