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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        while(head) {
            v.push_back(head->val);
            head = head->next;
        }
        
        vector<int> critical;
        
        for (decltype(v.size()) i = 1; i != v.size() - 1; ++i) {
            if (v[i - 1] > v[i] && v[i] < v[i + 1]) {
                critical.push_back(i);
            }
            if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
                critical.push_back(i);
            }
        }
        
        int min = 10000000;
        int max = -1;
        for (decltype(critical.size()) i = 1; i < critical.size(); ++i) {
            int tmp = critical[i] - critical[i - 1];
            if (tmp < min) {
                min = tmp;
            }
        }
        if (min == 10000000) min = -1;
        if (critical.size() >= 2) {
            max = critical.back() - critical[0];
        }
          
        return {min, max};
    }
};

int main() {
  
  
  return 0;  
}
