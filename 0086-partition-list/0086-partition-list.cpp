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
    -   space complexity O(1) - we can split and reunion the splited nodes;
    - time complexity O(n)


*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode dummy1 , dummy2;
        ListNode* headElements = &dummy1;
        ListNode* tail = &dummy2;
        ListNode* iterator = head;
        
        while( iterator != nullptr){
            ListNode* next = iterator->next;

            if(iterator->val < x){
                headElements->next = iterator;
                iterator -> next = nullptr;
                headElements = headElements->next;
            }
            else{
                tail->next = iterator;
                iterator -> next = nullptr;
                tail = tail->next;
            }
            iterator = next;
        }
        
        headElements->next = dummy2.next;
        
        return dummy1.next;
        
    }
};