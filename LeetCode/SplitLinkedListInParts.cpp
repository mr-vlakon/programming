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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *tmp = head;
        int cnt = 0;
        while(tmp) {
            ++cnt;
            tmp = tmp->next;
        }
        int part = 1;
        bool status = true;
        if (k < cnt) {
            status = false;
            part = min((cnt / k) + (cnt % k), (cnt / k) + 1);
        } 
        vector<ListNode*> answer;
        int counter = 0;
        int size = 1;
        int tmpSize = part;
        ListNode *start = head;
        while (head) {
            ++counter;
            if (counter == part) {
                auto temp = head;
                head = head->next;
                temp->next = nullptr;
                counter = 0;
                answer.push_back(start);
                start = head;
                if (!status) {
                    if ((k - size) != 0) {
                        part = min((cnt - tmpSize) / (k - size) +  (cnt - tmpSize) % (k - size),
                        (cnt - tmpSize) / (k - size) + 1);
                    } else {
                        part = cnt - tmpSize;
                    }
                }
                tmpSize += part;
                ++size;
            } else {
                head = head->next;
            }
        }
        if (counter != 0) {
            answer.push_back(start);
        }
        while (answer.size() < k) {
            answer.push_back(nullptr);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
