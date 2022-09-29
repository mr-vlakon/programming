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
    void height(TreeNode *root, int i) {
        if (root == nullptr) {
            v.push_back(i);
            return;
        }
        height(root->left, i + 1);
        height(root->right, i + 1);
    }
    
    void traverse(TreeNode *root, int i) {
        if (root == nullptr) return;
        result[i].push_back(root->val);
        traverse(root->left, i + 1);
        traverse(root->right, i + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int i = 0;
        height(root, i);
        int size = *max_element(v.cbegin(), v.cend());
        result.resize(size);
        traverse(root, i);
        vector<double> answer;
        for (const auto &e: result) {
            double tmp = accumulate(e.cbegin(), e.cend(), 0.0);
            answer.push_back(tmp/e.size());
        }
        return answer;
        
    }
private:
    vector<int> v;
    vector<vector<int>> result;
};

int main() {

  
  return 0;  
}
