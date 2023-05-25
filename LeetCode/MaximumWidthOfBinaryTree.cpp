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
    void traverse(TreeNode * &root, unsigned long long i, int level) {
        if (root == nullptr) return;
        if (v[level] == -1) {
            v[level] = i;
        } else {
            answer = max(static_cast<int>(i - v[level]) + 1, answer);
        }
        traverse(root->left, 2*i, level + 1);
        traverse(root->right, 2*i + 1, level + 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int height_ = height(root);
        v.resize(height_, -1);
        traverse(root, 0, 0);
        return answer;
    }
private:
    int answer = 1;
    vector<int> v;
};

int main() {
  
  
  
  return 0;  
}
