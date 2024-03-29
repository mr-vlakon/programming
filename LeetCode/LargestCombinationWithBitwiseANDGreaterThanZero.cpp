/*
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        unordered_map<int, int> um;
        int num = 0;
        int k = 0;
        int answer = 0;   
        for (const auto &e: candidates) {
            k = 0;
            while (k != 31 && (e >= (1 << k))) {
                num = (e & (1 << k));
                if (num != 0) {
                    um[k]++;
                    answer = max(answer, um[k]);
                }
                ++k;
            }
        }
        return answer;
    }
};
*/

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> hash(31, 0);
        int num = 0;
        int k = 0;
        int answer = 0;   
        for (const auto &e: candidates) {
            k = 0;
            while (k != 31 && (e >= (1 << k))) {
                num = (e & (1 << k));
                hash[k] += (num > 0) ? 1 : 0;
                ++k;
            }
        }
        for (const auto &e: hash) {
            answer = max(answer, e);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
