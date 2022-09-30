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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<int> vlist1;
        while(list1) {
            vlist1.push_back(list1->val);
            list1 = list1->next;
        }
        
        vector<int> vlist2;
        while(list2) {
            vlist2.push_back(list2->val);
            list2 = list2->next;
        }
        
        vector<int> res;
        int ind = 0;
        while (ind != a) {
            res.push_back(vlist1[ind]);
            ++ind;
        }
        
        ind = 0;
        while (ind < vlist2.size()) {
            res.push_back(vlist2[ind]);
            ++ind;
        }
        
        ind = b + 1;
        while (ind <= vlist1.size() - 1) {
            res.push_back(vlist1[ind]);
            ++ind;
        }
        
        if (res.size() == 0) return nullptr;       
        ListNode *ln = new ListNode(res[0]);
        ListNode *head = ln;
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
