
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned i1 = 0, i2 = 0, cnt1 = 1, cnt2 = 1;
        ListNode *resultNode = l1;
        ListNode *addNode = l2;
        vector<unsigned> v1, v2;
        
        while (l1 != nullptr ) {
            unsigned tmp = l1->val;
            v1.push_back(tmp);
            l1 = l1->next;
        } 
        while(l2 != nullptr) {
            v2.push_back(l2->val);
            l2 = l2->next;
        } 

        vector<unsigned> v;
        unsigned temp = 0;
        unsigned ost = 0;
        decltype(v1.size()) max = v1.size() > v2.size() ? v1.size() : v2.size();
        decltype(v1.size()) q = 0;
        decltype(v1.size()) min = v1.size() < v2.size() ? v1.size() : v2.size();
        while(q != max) {
            if (q < min) {
                temp = v1[q] + v2[q] + ost;
                if (temp >= 10) {
                    v.push_back(temp % 10);
                    ost = temp / 10;
                } else {
                    v.push_back(temp);
                    ost = 0;
                }
            } else {
                unsigned trp = (v1.size() > v2.size()) ? v1[q] : v2[q];
                temp = trp + ost;
                if (temp >= 10) {
                    v.push_back(temp % 10);
                    ost = temp / 10;
                } else {
                    v.push_back(temp);
                    ost = 0;
                }
            }
            if (q == max - 1 && ost != 0) {
                v.push_back(ost);
            }                
            ++q;
        }
        
        decltype(v.size()) j = 0;
        ListNode *ptr = resultNode;
        
        while(j != v.size()) {
            if (ptr->next == nullptr) {
                if (addNode != nullptr) {
                    ptr->next = addNode;
                    addNode = addNode->next;
                } else {
                }
            }           
            if (j == v.size() - 1) {
                *ptr = ListNode(v[j], nullptr);
                break;
            } else {
                *ptr = ListNode(v[j], ptr->next);
            }
            ptr = ptr->next;
            ++j;
        } 
        return resultNode;
    }
};

int main() {

  return 0;
}
