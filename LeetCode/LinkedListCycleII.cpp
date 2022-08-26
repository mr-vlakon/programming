struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        vector<pair<size_t,ListNode *>> v;
        ListNode *ptr = head;
        size_t index = 0;
        while(head != nullptr) {
            auto it = find_if(v.cbegin(), v.cend(),
            [=](const pair<size_t, ListNode*> &lhs) {
               return lhs.second == head->next;
            }
            );
            if (it == v.cend()){
                v.push_back({index, head});
            } else {
                return (*it).second;
            }
            head = head->next;
            ++index;
        }
        return nullptr;        
    }
};

int main() {
  return 0;
}
