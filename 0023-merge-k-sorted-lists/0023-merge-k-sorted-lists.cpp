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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())  return NULL;
        
        // create minHeap
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> minHeap;
        ListNode* cur = new ListNode(0);
        ListNode* curPtr=cur;

        // insert all starting points of lists with it's value
        for(ListNode* node: lists)
        {
            if(node)
                minHeap.push({node->val,node});
        }

        while(!minHeap.empty())
        {
            // get the min element & add it to the list
            // also move its pointer to its next
            ListNode* temp=minHeap.top().second;
            cur->next = temp;
            temp = temp->next;
            
            // pop the min node & push its next pointer node (avoid pushing NULL)
            minHeap.pop();
            if(temp)
                minHeap.push({temp->val,temp});

            cur=cur->next;
        }

        return curPtr->next;
    }
};