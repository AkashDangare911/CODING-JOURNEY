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
    void findDiff(TreeNode* root, TreeNode* &prev, int &ans)
    {
        if(!root)
            return;
        
        findDiff(root->left,prev,ans);

        if(prev)
            ans = min(ans,abs(root->val-prev->val));
        prev=root;
    
        findDiff(root->right,prev,ans);
    }
public:
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        TreeNode* prev=NULL;
        findDiff(root,prev,ans);
        return ans;
    }
};