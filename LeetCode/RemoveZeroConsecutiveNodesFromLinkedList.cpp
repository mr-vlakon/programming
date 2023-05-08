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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *res = head;
        unordered_set<int> us;
        unordered_set<int>::iterator it;
        int tmp = 0;
        int t = 0;
        deque<int> q;
        while (head) {
            tmp += head->val;
            if (tmp == 0) {
                t = tmp - head->val;
                while (!q.empty()) {
                    us.erase(t);
                    t -= q.back();
                    q.pop_back();
                }
            } else {
                it = us.find(tmp);
                if (it != us.cend()) {
                    t = tmp - head->val;
                    while (!q.empty() && t != tmp) {
                        us.erase(t);
                        t -= q.back();
                        q.pop_back();
                    }
                } else {
                    q.push_back(head->val);
                }
                us.insert(tmp);
            }
            head = head->next;
        }
        if (q.size() == 0) return nullptr;
        ListNode *temp = res;
        while (!q.empty()) {
            temp->val = q.front();
            if (q.size() != 1) {
                temp = temp->next;
            } else {
                temp->next = nullptr;
            }
            q.pop_front();
        }
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}
