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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode * top = head;
        ListNode *prev = head;
        while (top) {
            prev = top;
            top = top->next;
            if (top != nullptr) {
                prev->next = new ListNode(gcd(prev->val, top->val));
                prev = prev->next;
                prev->next = top;
            }      
        }
        return head;
    }
};

int main() {



  return 0;
}
