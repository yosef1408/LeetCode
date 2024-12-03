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


    /*
    idea of solution:
    1.find the length of the list (iterate over it ) and then calucate the rotate actual K = K % size;
    2. if k == 0 return the same list , or head == null o head->next == null;
    3. build new list (in line  => O(1)) (first we point to node[k]), we can do that using 2 while loops;
    lets take a look at given example => k = 2 , list = [1,2,3,4,5];
    3.A: tail = [1,2,3] (0 -> len - k)
    3.B: head = [4,5] (len - k -> len)
    res = Combine(B,A);
    5.return res;

    time complexity: iterating over the list O(n) , n = size of the list; finding the size (etc.. ) take O(n);
    space complexity: O(1) in-line changes;
    */
        
    int length(ListNode* head)
    {
        if(head == nullptr)
            return 0;
        
        int len = 0;
        while(head != nullptr){
            len++;
            head = head->next;
        }

        return len;
    }
public:

    ListNode* rotateRight(ListNode* head, int k) {

        if(k == 0 || head == nullptr || head->next == nullptr)
            return head;
        
        int n = length(head);
        k = k % n;

        if(k == 0 )
            return head;

        ListNode* newtail = head;
        ListNode* newhead;

        for(int i = 0 ; i < (n - k) -1 ; i++)
            newtail = newtail->next;
        

        newhead = newtail -> next;
        newtail->next = nullptr;
        ListNode* it = newhead;

        while(it != nullptr && it->next != nullptr)
        {
            it = it->next;
        }
        if(it != nullptr ) it->next = head;
        return newhead;



    }
};