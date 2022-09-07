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
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        ListNode *ptr = head;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        reverse(v.begin(), v.end());
        int res = 0;
        for (decltype(v.size()) i = 0; i != v.size(); ++i) {
            res += v[i] * pow(2, i);
        }
        
        return res;
    }
};

int main() {
  

  return 0;
}
