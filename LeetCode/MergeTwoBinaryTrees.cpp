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
    void traverse(TreeNode * &root1, TreeNode * &root2) {
        if (root1 == nullptr) return;
        if (root2 == nullptr) return;
        root1->val += root2->val;
        if (root1->left == nullptr && root2->left != nullptr) {
            root1->left = root2->left;
        } else {
            traverse(root1->left, root2->left);
        }   
        if (root1->right == nullptr && root2->right != nullptr) {
            root1->right = root2->right;
        } else {
            traverse(root1->right, root2->right);
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        traverse(root1, root2);
        return (root1 == nullptr) ? root2 : root1;
    }
};

int main() {
  
  
  return 0;  
}
