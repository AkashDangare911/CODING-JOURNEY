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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp=head;

        // find length
        int l=0;
        while(temp)
        {
            temp = temp->next;
            l++;
        }
      
        // remove last node / list contains single node
        if(l==n || l==1)
            return head->next;      
        
        // find nth node from last
        int z = l-n-1;
        temp = head;

        // run to find that node
        while(z>0)
        {
            temp = temp->next;
            z--;
        }

        // delete the node
        temp-> next = temp->next->next;
        return head;
    }
};