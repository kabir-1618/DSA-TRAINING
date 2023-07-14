bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;   // Slow pointer moves one step at a time
    struct ListNode *fast = head;   // Fast pointer moves two steps at a time

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           // Move slow pointer one step
        fast = fast->next->next;     // Move fast pointer two steps

        if (slow == fast) {
            // The slow and fast pointers meet, indicating a cycle
            return true;
        }
    }

    // No cycle found
    return false;
}
