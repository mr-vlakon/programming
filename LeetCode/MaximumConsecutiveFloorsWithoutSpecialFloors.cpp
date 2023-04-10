class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int answer = 0;
        sort(special.begin(), special.end());
        if (bottom < special[0]) {
            answer = special[0] - bottom;
        }
        for (int i = 1; i != special.size(); ++i) {
            if (special[i] > top) break;
            answer = max(answer, special[i] - special[i - 1] - 1);
        }
        if (top > special.back()) {
            answer = max(answer, top - special.back());
        }      
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
