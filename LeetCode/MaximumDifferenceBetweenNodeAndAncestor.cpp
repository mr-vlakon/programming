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
    void findMinMax(TreeNode *&root, int & min, int  & max) {
        if (root == nullptr) {
            return;
        }
        if (root->val < min) {
            min = root->val;
        }
        if (root->val > max) {
            max = root->val;
        }
        findMinMax(root->left, min, max);
        findMinMax(root->right, min, max);   
    }
    
    
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        int min = 100000;
        int max = -2;
        findMinMax(root, min, max);
        v.push_back(abs(root->val - min));
        v.push_back(abs(root->val - max));
        traverse(root->left);
        traverse(root->right);
    }
    
    
    int maxAncestorDiff(TreeNode* root) {
        traverse(root);
        return *max_element(v.cbegin(), v.cend());
    }
    
private:
    vector<int> v;
};

int main() {
  
  
  return 0;  
}
