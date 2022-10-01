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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        head = head->next;
        vector<int> res;
        while(head) {
            int tmp = head->val;
            if (tmp == 0) {
                res.push_back(sum);
                sum = 0;
            } else {
                sum += tmp;
            }
            head = head->next;
        }
        
        if (res.size() == 0) return nullptr;       
        ListNode *ln = new ListNode(res[0]);
        head = ln;
        int index = 1;
        while (index < res.size()) {
            if (index <= res.size() - 1)
                ln->next = new ListNode(res[index], nullptr);
            ++index;
            if (index <= res.size()) {
                ln = ln->next;
            }
        }
        return head;           
    }
};

int main() {
  
  
  return 0;  
}
