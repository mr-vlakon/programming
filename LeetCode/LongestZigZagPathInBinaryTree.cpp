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
    void traverse(TreeNode *&root, int x, int prev) {
        if (root == nullptr) return;
        answer = max(x, answer);
        if (prev == 1) {
            ++x;
            traverse(root->left, x , 0);
            traverse(root->right, 1, 1);
        } else if (prev == 0) {
            ++x;
            traverse(root->left, 1, 0);
            traverse(root->right, x, 1);
            
        } else {
            ++x;
            traverse(root->left, x, 0);
            traverse(root->right, x, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        traverse(root, 0, -1);
        return answer;
    }
private:
    int answer = 0;
};

int main() {
  
  
  
  
  return 0;  
}
