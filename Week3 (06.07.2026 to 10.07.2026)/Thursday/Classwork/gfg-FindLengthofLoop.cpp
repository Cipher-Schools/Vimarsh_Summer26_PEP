class Solution {
public:
    int countNodesinLoop(Node *head) {
        Node *slow = head;
        Node *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // Loop detected
                int count = 1;
                Node *temp = slow;
                while (temp->next != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }
        return 0; // No loop
    }
};