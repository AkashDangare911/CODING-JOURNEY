/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;

        while(head)
        {
            // if a node is found again, it is the starting point
            if(mp.count(head)){
                return head;
            }

            mp[head]=1;
            head=head->next;
        }

        return nullptr;
    }
};