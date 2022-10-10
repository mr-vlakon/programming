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
    void traverse(TreeNode * &root, int status) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr && status) {
            s += root->val;
        }
        traverse(root->left, 1);
        traverse(root->right, 0);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        traverse(root, 0);
        return s;
    }
private:
    int s = 0;
};

int main() {
  
  return 0;  
}
