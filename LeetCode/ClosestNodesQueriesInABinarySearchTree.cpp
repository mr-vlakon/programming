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
    void traverse(TreeNode * &root) {
        if (root == nullptr) return;
        v.push_back(root->val);
        traverse(root->left);
        traverse(root->right);
        
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> answer;
        traverse(root);
        sort(v.begin(), v.end());
        
        for (const auto &e: queries) {
            auto lb = lower_bound(v.cbegin(), v.cend(), e);
            int mini = 0;
            int maxi = 0;
            if (lb == v.cend()) {
                --lb;
                if (*lb >= e)
                    maxi = *lb;
                else 
                    maxi = -1;
                
                if (*lb > e) {
                    mini = -1;
                } else {
                    mini = *lb;
                }
            } else {
                auto tmp = *lb;
                auto second = 0;
                if (lb != v.cbegin()) {
                    maxi = *lb;
                    --lb;
                    second = *lb;
                    if (second <= e) {
                        mini = second;
                    }
                    if (second <= tmp && tmp <= e) {
                        mini = tmp;
                    }
                } else {
                    maxi = tmp;
                    if (*lb <= e)
                        mini = tmp;
                    else
                        mini = -1;
                }    
            }
            answer.push_back({mini, maxi});
        }
        return answer;
    }
private:
    vector<int> v;

};

int main() {
  
  
  
  return 0;  
}
