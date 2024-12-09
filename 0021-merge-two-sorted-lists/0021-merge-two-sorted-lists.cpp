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

/*
    lets 
    
    PsudoCode:
    - maintain two pointers. the first pointer iterate over the first list, the secound iterate over the secound            list; (APointer,BPointer)
    
    - if any of the given list is empty return the secound list;
    - while iterating, build carfully the new list, taken in cosideration saving the lastNode , and checking hows           bigger
    - return the same list after sorting;
    
    lastNode;
    if (Apointer->val == Bpointer->val){
        
        temp  = Apointer->next;
        Apointer->next = Bpointer;
        Bpointer++;
        Apointer = temp;
    }
    else(Apointer->val > Bpointer->val){
        
    }
*/
class Solution {
public:        
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to simplify edge cases
        ListNode dummy;
        ListNode* tail = &dummy;

        // Merge the two lists
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining nodes
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};
