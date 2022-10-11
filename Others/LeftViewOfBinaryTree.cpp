
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
vector<vector<int>> v;
vector<int> hg;
void height(Node * &root, int i) {
    if (root == nullptr) return;
    if (root->left == nullptr  && root->right == nullptr) {
        hg.push_back(i);
    }
    height(root->left, i + 1);
    height(root->right, i + 1);
}

void traverse(Node * &root, int i) {
    if (root == nullptr) {
        return;
    }
    v[i].push_back(root->data);
    traverse(root->left, i + 1);
    traverse(root->right, i + 1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    v.resize(0);
    hg.resize(0);
    if (root == nullptr) return {};
    height(root, 1);
    int x = *max_element(hg.cbegin(), hg.cend());
    v.resize(x);
    traverse(root, 0);
    vector<int> res;
    for (const auto &e: v) {
        res.push_back(e[0]);
    }
    return res;
}

int main() {
  
  
  return 0;  
}
