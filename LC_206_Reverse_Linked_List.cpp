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
// O(n) solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        // Variable that will represent the current node's
        // original previous node
        ListNode* prevTemp = nullptr;
        
        // Once the head is null, the end of the linked list is reached
        while (head != nullptr)
        {
            // Save the next pointer so we can traverse the list because we will change the 
            // next of the current to its previous pointer (since we are reversing the list)
            auto nextPtr = head->next;
            // Sets the current pointer's next to its previous node (reversing it)
            head->next = prevTemp;
            // Sets the previous node pointer variable to itself since we will be
            // moving to the next pointer
            prevTemp = head;
            // Moves to the next pointer (in the original traversal order)
            head = nextPtr;
        }
        // Once the head is null, the previous pointer should be the new head
        // of the reversed linked list.
        return prevTemp;
    }
};
