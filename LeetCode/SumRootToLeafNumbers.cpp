 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode * &root, string s) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            s += to_string(root->val);
            v.push_back(s);
            return;
        }
        s += to_string(root->val);
        traverse(root->left, s);
        traverse(root->right, s);
        
    }
    int sumNumbers(TreeNode* root) {
        traverse(root, "");
        int sum = 0;
        for (const auto &e: v) {
            sum += stoi(e);
        }
        return sum;
    }
private:
    vector<string> v;
};

int main() {
  
  return 0;  
}
