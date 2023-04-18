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
        if (root == nullptr) {
            return 0;
        }
        return max(height(root->left), height(root->right)) + 1;
    }
    void traverse(TreeNode * &root, int i, const int &h) {
        if (root == nullptr) return;
        ++v[i];
        if (i == (h - 2)) {
            v1.push_back(root);
        } else if (i == (h - 1)) {
            v2.push_back(root);
        }
        traverse(root->left, i + 1, h);
        traverse(root->right, i + 1, h);
    }

    bool isCompleteTree(TreeNode* root) {
        const int h = height(root);
        v.resize(h);
        traverse(root, 0, h);
        int start = 1;
        for (int i = 0; i != (v.size() - 1); ++i) {
            if (v[i] != start) {
                return false;
            }
            start *= 2;
        }        
        for (int j = 0; j != v1.size(); ++j) {
            if ((2*j < v2.size()) && v1[j]->left != v2[2*j]) {
                return false;
            }
            if ((2*j + 1) < v2.size() && v1[j]->right != v2[2*j + 1]) {
                return false;
            }
        }
        return true;
    }
private:
    vector<int> v;
    vector<TreeNode*> v1;
    vector<TreeNode*> v2;
};

int main() {
  
  
  return 0;  
}
