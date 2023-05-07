class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> st;
        if (head != nullptr) {
            st.push(head);
        }
        Node *top = 0;
        vector<Node*> v;
        while (!st.empty()) {
            top = st.top();
            st.pop();
            v.push_back(top);
            if (top->next) st.push(top->next);
            if (top->child) st.push(top->child);
        }
        Node *res = head;
        for (int i = 0; i != v.size(); ++i) {
            head = v[i];
            if ((i + 1) < v.size()) {
                head->next = v[i + 1];
            } else {
                head->next = nullptr;
            }
            head->child = nullptr;
            if ((i - 1) >= 0) {
                head->prev = v[i - 1];
            } else {
                head->prev = nullptr;
            }
            head = head->next;    
        }
        return res;       
    }
};

/*
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
*/

int main() {
  
  
  
  
  
  return 0;  
}
