//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    private:
    Node *rev(Node *head)
    {
        Node *prev=NULL;
        Node *cur=head;
        Node *nxt=NULL;
        
        while(cur)
        {
            nxt = cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        
        return prev;
    }
    
    public:
    void rearrange(struct Node *head)
    {
        Node *temp=head;
        
        Node *head2= new Node(0);
        Node *ptr2=head2; 
        
        // 10 9 3 9 4 5 1 4
        
        while(temp && temp->next)
        {
            ptr2->next=temp->next;
            ptr2=ptr2->next;
            
            if(!temp->next->next)
                break;
            temp->next = temp->next->next;
            temp=temp->next;
        }
        
        temp->next=nullptr;
        ptr2->next=nullptr;
        temp->next = rev(head2->next);
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends