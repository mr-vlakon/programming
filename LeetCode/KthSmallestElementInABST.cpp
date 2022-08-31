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
    void traversal(TreeNode *root) {
        if (root == nullptr) return;
        v.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) return {};
        traversal(root);
        sort(v.begin(), v.end());
        return *(v.begin() + k - 1);               
    }
private:
     vector<int> v;
};

int main() {
  
  return 0;  
}
