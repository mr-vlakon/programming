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
    
    void traverse(TreeNode * &root, const int &x) {
        if (root == nullptr) return;
        if (root->val == x) {
            
            if (root->left != nullptr) {
                answer.push_back(root->left);
            }
            if (root->right != nullptr) {
                answer.push_back(root->right);
            }
            root = nullptr;
            return;
        }
        
        traverse(root->left, x);
        traverse(root->right, x);
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        sort(to_delete.rbegin(), to_delete.rend());
        for (const auto &e: to_delete) {
            traverse(root, e);
        }
        if (root != nullptr)
            answer.push_back(root);
        return answer;
    }
    
private:
    vector<TreeNode *> answer;
};

int main() {
  
  
  
  return 0;  
}
