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
    int sumAll (TreeNode * &root, int curr, int maxV) {
        if (root == nullptr) return maxV;
        answer = max(root->val, answer);
        curr += root->val;
        if (curr > maxV) {
            maxV = curr;
        }
        return max(sumAll(root->left, curr, maxV), sumAll(root->right, curr, maxV));
    }
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        um[root] = sumAll(root->left, 0, 0) + sumAll(root->right, 0, 0) + root->val;
        answer = max(um[root], answer);
        traverse(root->left);
        traverse(root->right);
    }
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return answer;
    }
private:
    unordered_map<TreeNode*, int> um;
    int answer = INT_MIN;
};

int main() {
  
  
  
  return 0;  
}
