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
    int sumOfTree(TreeNode *root) {
        if (root == nullptr) return 0;
        return root->val + sumOfTree(root->left) + sumOfTree(root->right);
    }

    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        int l = sumOfTree(root->left);
        int r = sumOfTree(root->right);
        res.push_back(abs(l - r));
        traverse(root->left);
        traverse(root->right);
        
    }
    int findTilt(TreeNode* root) {
        traverse(root);
        return accumulate(res.cbegin(), res.cend(), 0);
    }
private:
    vector<int> res;
    int sum = 0;
};

int main() {
  
  
  return 0;  
}
