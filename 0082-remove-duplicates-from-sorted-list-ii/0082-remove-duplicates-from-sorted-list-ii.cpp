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
    -   we can solve it using two pointer approach, the first pointer is keep moving(iterating) the secound point where to insert the new value;
    -   time complexity is O(n) , n present the list length; Space complexity = O(1), i change the current list;



 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        //Don't forget handling edge cases;

        if(head == nullptr || head->next == nullptr)
            return  head;
        
        ListNode* insertPointer = head; //Pointing to the end of the new list;
        ListNode* itPointer = head->next;//Iterating over the list;
        ListNode* prevNode = head;
        int currVal = head->val;
        bool duplicate = false;

        while(itPointer != nullptr){

            if(currVal == itPointer->val)
                duplicate = true;


            if(currVal != itPointer->val){
                if(duplicate == true)
                    currVal = itPointer->val;
                else
                {
                    prevNode = insertPointer;
                    insertPointer->val = currVal;
                    currVal =  itPointer->val;
                    insertPointer = insertPointer->next;
                }

                duplicate = false;
            }

            itPointer= itPointer->next;     
        }


        //Handling the tail;
        if(currVal != prevNode->val && duplicate == false)
            {
                prevNode = insertPointer;
                insertPointer->val = currVal;
                insertPointer = insertPointer->next;          
            }

        if(insertPointer == head)
            return nullptr;


        prevNode->next = nullptr;

        //Freeing all the unessarynode;
        while(insertPointer != nullptr){

            ListNode* temp = insertPointer->next;
            delete(insertPointer);
            insertPointer = temp;
        }

        return head;

        
        
    }
};