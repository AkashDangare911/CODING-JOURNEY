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
    TreeNode* buildTree(int st, int en, vector<int> &nums)
    {
        if(st>en)
            return NULL;
        
        int mid = (st+en)/2;
        TreeNode* cur = new TreeNode(nums[mid]);

        cur->left = buildTree(st,mid-1,nums);
        cur->right = buildTree(mid+1,en,nums);

        return cur;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(0,nums.size()-1,nums);
    }
};