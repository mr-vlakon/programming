struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<pair<int,ListNode*> > v1, v2;
        while (headA != nullptr) {
            v1.push_back({headA->val, headA});
            headA = headA->next;
        }
        while (headB != nullptr) {
            v2.push_back({headB->val, headB});
            headB = headB->next;
        }
        for(const auto &e : v1) {
            for (const auto &q: v2) {
                if (e.second == q.second) {
                    return e.second;
                }
            }
        }
        return nullptr;
    }
};

int main() {
  return 0; 
}
