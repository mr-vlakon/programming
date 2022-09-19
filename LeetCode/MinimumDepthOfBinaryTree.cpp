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
    void traversal(TreeNode *root, int i) {
        if (root == nullptr) {
            return;
        }
        if ((root->left == nullptr) && (root->right == nullptr)) {
            v.push_back(i);
        }
        traversal(root->left, i + 1);
        traversal(root->right, i + 1);
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        traversal(root, 1);
        return *min_element(v.cbegin(), v.cend());    
    }
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
