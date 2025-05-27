/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* newHead = new Node(0);
        Node* headPtr = newHead;
        Node* cur=head;

        // map original list nodes with the newly created nodes
        while(cur)
        {
            Node* n = new Node(cur->val);
            newHead->next=n;
            newHead=n;
            mp[cur]=n;
            cur=cur->next;
        }

        cur=head;

        // again traverse on original list
        // get the 'randomPtr' of original list node and its corresponding new node as 'nodeFromMap' 
        // also get the corrsponding new node for the random node as 'cur->random'
        while(cur)
        {
            Node* nodeFromMap = mp[cur];
            nodeFromMap->random = mp[cur->random];
            cur=cur->next;
        }

        return headPtr->next;
    }
};