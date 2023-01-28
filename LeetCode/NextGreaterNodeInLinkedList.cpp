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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> st;
        vector<int> answer;
        while (head) {
            answer.push_back(head->val);
            head = head->next;
        }
        vector<int> result(answer.size());
        for (int i = answer.size() - 1; i >= 0; --i) {
            while ((st.size() != 0) && st.top() <= answer[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                result[i] = 0;
            } else {
                result[i] = st.top();
            }
            st.push(answer[i]);
        }       
        return result;
    }
};

int main() {
  
  
  
  
  return 0;  
}
