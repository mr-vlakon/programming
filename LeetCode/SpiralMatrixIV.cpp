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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> answer(m, vector<int>(n, -1));
        int startRow = 0;
        int startCol = 0;
        int bordLeft = 0;
        int bordRight = n - 1;
        int bordUp = 0;
        int bordDown = m - 1; 
        int direction = 0;
        while (head) {
            answer[startRow][startCol] = head->val;
            head = head->next;
            if (startCol == bordRight && startRow == bordUp && direction == 0) {
                startRow++;
                bordUp++;
                direction = 1;
            } else if (startRow == bordDown && startCol == bordRight && direction == 1) {
                --bordRight;
                --startCol;
                direction = 2;
            } else if (startRow == bordDown && startCol == bordLeft && direction == 2) {
                direction = 3;
                --startRow;
                --bordDown;
            } else if (startRow == bordUp && startCol == bordLeft && direction == 3) {
                direction = 0;
                ++startCol;
                ++bordLeft;
            } else if (direction == 0) {
                ++startCol;
            } else if (direction == 1) {
                ++startRow;
            } else if (direction == 2) {
                --startCol;
            } else {
                startRow--;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
