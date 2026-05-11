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
    void getInorder(TreeNode* root, vector<int> &inorder)
    {
        if(!root)
            return;
        
        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
    }

    void fillInorder(TreeNode* root, int &curInd, vector<int> &inorder)
    {
        if(!root)
            return;
        
        fillInorder(root->left,curInd,inorder);
        root->val=inorder[curInd++];
        fillInorder(root->right,curInd,inorder);
    }
public:
    // TC - O(n) + O(logn) + O(n)
    // SC -o(N)
    void recoverTree(TreeNode* root) {
        vector<int> inorder;
        getInorder(root,inorder);
        sort(inorder.begin(),inorder.end());
        
        int curInd=0;
        fillInorder(root,curInd,inorder);
    }
};