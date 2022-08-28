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
    ListNode* middleNode(ListNode* head) {
        vector<pair<int,ListNode*>> v;
        ListNode *ptr = head;
        while (head != nullptr) {
            v.push_back({head->val, head});
            head = head->next;
        }
        if (v.size() == 0) return nullptr;        
        return v[v.size()/2].second;
    }
};

int main() {
  
  return 0;
}
