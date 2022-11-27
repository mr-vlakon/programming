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
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> v;
        stack<int> st;
        ListNode * res = head;
        while (head) {
                if (!st.empty() && (head->val <= st.top() )) {
                    st.push(head->val);
                } else {
                    while (!st.empty() && (head->val > st.top())) {
                        st.pop();
                    }
                    st.push(head->val);
                }
            v.push_back(head->val);
            head = head->next;
        }
        
        stack<int> newStack;
        while (!st.empty()) {
            auto top = st.top();
            newStack.push(top);
            st.pop();
        }
        
        vector<int> result;
        while(!newStack.empty()) {
            auto top = newStack.top();
            result.push_back(top);
            newStack.pop();
        }
        ListNode *tmp = res;
        int i = 0;
        while (i != result.size()) {    
            tmp->val = result[i];
            if (i != result.size() - 1) {
                tmp = tmp->next;
            } else {
                tmp->next = nullptr;
            }
            ++i;
        }
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}
