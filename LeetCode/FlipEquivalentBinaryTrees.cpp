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
    void traverse(TreeNode* &p, TreeNode* &q) {
        if (p == nullptr) return;
        if (q == nullptr) return;
        if (p->left && q->left && p->left->val != q->left->val) {
            swap(p->left, p->right);
        }
        if (p->left == nullptr && q->left) {
            swap(p->left, p->right);
        }
        if (p->right == nullptr && q->right) {
            swap(p->left, p->right);
        }
        traverse(p->left, q->left);
        traverse(p->right, q->right);
    }
    bool isSameTree(TreeNode* &p, TreeNode* &q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;
        if (p->val != q->val) return false;    
        if (p->left == nullptr && q->left != nullptr) return false;
        if (p->left != nullptr && q->left == nullptr) return false;
        if (p->right == nullptr && q->right != nullptr) return false;
        if (p->right != nullptr && q->right == nullptr) return false;        
        if (p->left == nullptr && q->left == nullptr) {
            return isSameTree(p->right, q->right);
        }
        if (p->right == nullptr && q->right == nullptr) {
            return isSameTree(p->left, q->left);
        }
        if (p->left->val != q->left->val) return false;
        if (p->right->val != q->right->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        traverse(root1, root2);
        return isSameTree(root1, root2);
    }
};

int main() {
  
  
  
  return 0;  
}
