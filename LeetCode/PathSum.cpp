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
public:
    void traverse(TreeNode * &root, int sum) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            if (sum == target)
                status = true;
            return;
        }
        sum += root->val;
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverse(root, 0);
        return status;
    }
private:
    int target = 0;
    bool status = false;
};

int main() {
  
  
  return 0;  
}
