/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void findV(TreeNode *& root, int i) {
        if (i == v.size()) {
            status = true;
            return;
        }
        if (root == nullptr) {
            return;
        }
        if (root->val == v[i]) {
            findV(root->left, i + 1);
            findV(root->right, i + 1);
        }
    }
    void traverse(TreeNode *& root) {
        if (root == nullptr) return;
        if (root->val == v[0]) {
            findV(root, 0);
        }
        traverse(root->left);
        traverse(root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        traverse(root);
        return status;
    }
private:
    bool status = false;
    vector<int> v;
};

int main() {
  
  
  
  return 0;  
}
