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
    ListNode* mergeTwoLists(ListNode* &list1, ListNode* &list2) {
        ListNode* cur = new ListNode(0);
        ListNode* curPtr = cur;

        // untill one of the list exhausts
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                cur->next=list1;
                list1=list1->next;
            }
            else
            {
                cur->next=list2;
                list2=list2->next;
            }
            cur=cur->next;
        }

        // if any list exhausts, attach cur to other list 
        // as further nodes are already in sorted order
        if(list1)
            cur->next=list1;
        else
            cur->next=list2;

        return curPtr->next;
    }

    // recursively call for next sorted list head
    ListNode* solve(vector<ListNode*> &lists, int i)
    {
        // return the list for last index
        if(i>=lists.size()-1)
            return lists[i];
        
        // recurse till last index
        ListNode* sortedHead = solve(lists,i+1);
        // merge list present at next ptr and current list
        return mergeTwoLists(sortedHead,lists[i]);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
            return NULL;
        if(n==1)
            return lists[0];

        return solve(lists,0);
    }
};