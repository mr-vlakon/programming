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
    
    void create(TreeNode * &root, vector<int> v) {
        if (v.size() == 0) return;
        root = new TreeNode(v[v.size()/2]);
        create(root->left,{v.cbegin(), v.cbegin() + v.size() /2});
        create(root->right,{v.cbegin() + v.size() /2 + 1, v.cend()});
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        while (head) {
            vlist.push_back(head->val);
            head = head->next;
        }
        create(hd, vlist);
        return hd;
    }
private:
    TreeNode * hd = nullptr;
    vector<int> vlist;
};

int main() {
  
  
  return 0;  
}
