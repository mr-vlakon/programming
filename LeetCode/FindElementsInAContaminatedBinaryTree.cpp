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
class FindElements {
public:
    void traverse(TreeNode * &head) {
        if (head == nullptr) return;
        if (head->left != nullptr) {
            head->left->val = 2 * head->val + 1;
        }

        if (head->right != nullptr) {
            head->right->val = 2 * head->val + 2;
        }

        
        traverse(head->left);
        traverse(head->right);
    }
    
    bool trv(TreeNode *head, int target) {
        if (head == nullptr) return false;
        if (head->val == target) {
            return true;
        }
        return trv(head->left, target) || trv(head->right, target);
    }
    FindElements(TreeNode* root) {
        head = root;
        head->val = 0;
        traverse(head);
    }
    
    bool find(int target) {
        return trv(head, target);
    }
private:
    TreeNode *head = nullptr;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
  
  
  return 0;  
}
