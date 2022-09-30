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
    int sumOfTree(TreeNode * &root) {
        if (root == nullptr) return 0;
        return root->val + sumOfTree(root->left) + sumOfTree(root->right); 
    }
    
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        ++um[sumOfTree(root)];
        traverse(root->left);
        traverse(root->right);
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        for (const auto &e: um)
            v.push_back({e.first, e.second});
        sort(v.begin(), v.end(), 
             [=] (const pair<int, size_t> &lhs, const pair<int, size_t> &rhs) {
                return lhs.second > rhs.second; 
             });
        int max = v[0].second;
        vector<int> answer;
        for (const auto &e: v) {
            if (e.second == max)
                answer.push_back(e.first);
            else
                break;
        }
        
        return answer;
    }
private:
    unordered_map<int, size_t> um;
    vector<pair<int, size_t>> v;
    
};

int main() {
  
  
  return 0;  
}
