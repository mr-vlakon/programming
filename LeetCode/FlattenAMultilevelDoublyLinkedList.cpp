/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        Node *result = 0;
        if (head != nullptr) {
            st.push(head);
            result = new Node();
        }
        Node *res = result;
        Node *tmp = 0;
        Node *top = 0;
        while (!st.empty()) {
            top = st.top();
            st.pop();
            if (top->next) st.push(top->next);
            if (top->child) st.push(top->child);
            result->val = top->val;
            result->child = nullptr;
            result->next = (st.size() != 0) ? new Node() : nullptr;
            if (result->next)
                result->next->prev = (st.size() != 0) ? result : nullptr;;
            result = result->next;
        }
        return res;       
    }
};

int main() {
  
  
  
  
  
  return 0;  
}
