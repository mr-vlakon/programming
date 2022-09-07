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
    int pairSum(ListNode* head) {
        vector<int> v;
        ListNode *ptr = head;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        int max = 0;
        for (decltype(v.size()) i = 0; i != v.size(); i++) {
            if (v[i] + v[v.size() - i - 1] > max)
                max = v[i] + v[v.size() - i - 1];
        }   
        return max;   
    }
};

int main() {
  
  
  return 0;  
}
