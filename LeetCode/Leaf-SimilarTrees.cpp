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
        if (root->left == nullptr && root->right == nullptr && status == 1) {
            v1.push_back(root->val);
            return;
        }
        if (root->left == nullptr && root->right == nullptr && status == 2) {
            v2.push_back(root->val);
            return;
        }
        traverse(root->left, status);
        traverse(root->right, status);

    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1, 1);
        traverse(root2, 2);
        return v1 == v2;
    }
private:
    vector<int> v1;
    vector<int> v2;
};

int main() {
  
  
  return 0;  
}
