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
    void traverse(TreeNode *&root, string str) {
        if (root == nullptr) {
            return;
        }
        str.push_back(root->val + 'a');
        if (!root->left && !root->right) {
            reverse(str.begin(), str.end());
            answer = min(str, answer);
        }
        traverse(root->left, str);
        traverse(root->right, str);
    }
    string smallestFromLeaf(TreeNode* root) {
        string str;
        traverse(root, str);
        return answer;
    }
private:
    string answer = "zzzzzzz";
};

int main() {
  
  
  
  
  return 0;  
}
