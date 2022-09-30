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
    void traverse(TreeNode *&root, string s) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(s + to_string(root->val));
            return;
        }
        traverse(root->left, s + to_string(root->val));
        traverse(root->right, s + to_string(root->val));
    }
    
    int sumRootToLeaf(TreeNode* root) {
        traverse(root, "");
        int sum = 0;
        for (auto &e: res) {
            int ind = 0;
            int tmp = 0;
            reverse(e.begin(), e.end());
            while (ind != e.size()) {
                tmp += pow(2, ind) * (e[ind] - '0');
                ++ind;
            }
            sum += tmp;
            
        }
        return sum;
    }
private:
    vector<string> res;
};

int main() {
  
  
  
  return 0;  
}
