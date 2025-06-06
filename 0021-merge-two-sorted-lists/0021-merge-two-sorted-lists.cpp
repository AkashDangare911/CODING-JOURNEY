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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};