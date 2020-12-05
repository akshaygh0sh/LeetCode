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

// O(n + m) solution
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        auto tempList1 = list1;
        ListNode* newPrev = list2;
        bool reachA = false;
        while (tempList1->val != b)
        {
            if (tempList1->val == a)
            {
                reachA = true;
            }
            // Once you have reached the ath node (first node to be deleted)
            // delete all the nodes in between that node and the bth node (last node
            // to be deleted)
            if (reachA == true)
            {
                auto tempNext = tempList1->next;
                delete tempList1;
                tempList1 = tempNext;
            }
            // If you haven't reached the ath node, then set your previous node
            // (the node after which you will put the new linked list) to the current node
            // once node a is reached, this will not happen because we want the node before 
            // node a
            else
            {
                newPrev = tempList1;
                tempList1 = tempList1->next;
            }
        }
        // This deletes the bth node and saves the node after the bth node to the "next"
        // variable/node
        auto next = tempList1->next;
        delete tempList1;
        
        // Sets the previous pointer's (one before ath node) next node to the new linked list
        newPrev->next = list2;
        
        // Traverses second linked list till the end is reached
        ListNode* endList2 = list2;
        while (endList2->next != nullptr)
        {
            endList2 = endList2->next;
        }
        // Then sets the end of the second linked list's next pointer to the bth
        // node's next pointer
        endList2->next = next;

        return list1;
    }
};
