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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* current= head;
        int c=0;
        while(current!= NULL &&  c<k)
        {
            current= current->next;
            c++;
        }
        if(c==k){
            ListNode* p = reverseKGroup(current ,k);
            current=head;
            while(c--)
        {
            ListNode* temp= current->next;
            current->next=p;
            p=current;
            current=temp;
        }
        head=p;
    }
    return head;
    }
};