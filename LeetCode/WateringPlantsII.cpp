class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int start = 0;
        int end = plants.size() - 1;
        int answer = 0;
        int initialA = capacityA;
        int initialB = capacityB;
        while (start < end) {
            if (plants[start] > initialA) {
                initialA = capacityA;
                ++answer;
            }
            initialA -= plants[start];
            if (plants[end] > initialB) {
                initialB = capacityB;
                ++answer;
            }
            initialB -= plants[end];   
            ++start;
            --end;
        }
        if (start == end) {
            if (max(initialA, initialB) < plants[start]) {
                ++answer;
            }
        }
        return answer;
    }
};
/*
class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int start = 0;
        int end = plants.size() - 1;
        int answer = 0;
        int initialA = capacityA;
        int initialB = capacityB;
        while (start <= end) {
            if (start == end) {
                if (max(initialA, initialB) < plants[start]) {
                    ++answer;
                }
            } else {
                if (plants[start] > initialA) {
                    initialA = capacityA;
                    ++answer;
                }
                initialA -= plants[start];
                if (plants[end] > initialB) {
                    initialB = capacityB;
                    ++answer;
                }
                initialB -= plants[end];
            }
            ++start;
            --end;
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  return 0;
}
