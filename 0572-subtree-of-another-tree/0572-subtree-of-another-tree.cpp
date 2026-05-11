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
    bool isSame(TreeNode* first, TreeNode* second)
    {        
        if(!first && !second)
            return true;

        if(!first || !second)
            return false;
        
        if(first->val != second->val)
            return false;
        
        return isSame(first->left,second->left) && isSame(first->right,second->right); 
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        
        if(isSame(root,subRoot))
            return true;
        
        return isSubtree(root->left,subRoot) ||
                isSubtree(root->right,subRoot);
    }
};