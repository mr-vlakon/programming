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
    int height(TreeNode * &root) {
        if (root == nullptr) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    void traverse(TreeNode * &root, int height_, int row, int col) {
        if (root == nullptr) return;
        v[row][col] = to_string(root->val);
        traverse(root->left, height_ / 2, row + 1, col - height_);
        traverse(root->right, height_ / 2, row + 1, col + height_);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height_ = height(root);
        v.resize(height_);
        int start = 1;
        int tmp = 2;
        for (int i = 1; i < v.size(); ++i) {
            start += tmp;
            tmp *= 2;
        }
        for (auto &e: v) {
            e.resize(start);
        }
        int st = start;
        start /= 2;
        start /= 2;
        start += 1;
        traverse(root, start, 0, st / 2);
        return v;
    }
private:
    vector<vector<string>> v;
};

int main() {
  
  
  
  return 0;  
}
