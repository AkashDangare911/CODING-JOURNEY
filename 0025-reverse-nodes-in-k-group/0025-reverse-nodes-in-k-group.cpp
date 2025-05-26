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
private:
    // function to reverse linked list with given head
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head;
        ListNode *prev = NULL, *nextt = NULL;
        
        while(current)
        {
            nextt = current -> next;
            current ->next = prev;
            prev = current;
            current = nextt;
        }
        // return starting node of reversed list
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        ListNode *prevHead=NULL;    // to keep track of node in previous iteration of reversing
        bool isFirst=true;
        int cnt;

        // In each iteration, reverse StartNode to cur nodes
        while(cur)
        {
            // find starting 'k' nodes to reverse
            cnt=k-1;
            ListNode* startNode=cur;
            while(cur && cnt--) 
                cur=cur->next;
            
            // if we have sufficient nodes to reverse, then only move ahead
            if(cur)
            {
                // keep track of next node, for next iteration of reversing
                // dis-joint the links
                ListNode* nextNode=cur->next;
                cur->next=NULL;
                if(prevHead)
                    prevHead->next=NULL;

                // Reverse the dis-joint linked-list
                ListNode* revHead=reverseList(startNode);
                
                // only for first iteration, save the head node to return from function
                if(isFirst)
                {
                    head=revHead;
                    isFirst=false;
                }

                if(prevHead)
                    prevHead->next=revHead;

                // make link between last node of reversed-list and nextNode
                // for further iterations
                prevHead=startNode;
                startNode->next=nextNode;
                cur=nextNode;
            }
           
        }

        return head;
    }
};