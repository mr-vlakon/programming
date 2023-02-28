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
    void traverse(TreeNode *&root) {
        if (root == nullptr) {
            return;
        }  
        leftD = depth(root->left);
        rightD = depth(root->right);
        if ((leftD + rightD) < answer) {
            return;
        }
        answer = max(answer, leftD + rightD);
        traverse(root->left);
        traverse(root->right);    
    }
    int depth(TreeNode * &root) {
        if (root == nullptr) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root);
        return answer;        
    }
private:
    int leftD = 0;
    int rightD = 0;
    int answer = 0;
};

int main() {
  
  
  return 0;  
}
