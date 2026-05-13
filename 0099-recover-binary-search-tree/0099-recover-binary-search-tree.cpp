/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* prev;
    TreeNode *first;
    // TreeNode *middle;
    TreeNode *last;

    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        
        inorder(root->left);

        if(prev && prev->val > root->val)
        {
            // if the discrepancy happens for the first time
            if(!first)
            {
                first = prev;
                last = root;
            }
            else
                last = root; // if it happens again
        }

        prev=root;
        
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = last = NULL;

        inorder(root);

        // if the nodes are not adjacent
        if(first && last)
            swap(first->val,last->val);
    }
};