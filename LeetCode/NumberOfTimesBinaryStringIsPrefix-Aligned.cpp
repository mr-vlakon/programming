/*
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int answer = 0;
        int last1 = -1;
        for (int i = 0; i != flips.size(); ++i) {
            if (flips[i] > last1) {
                last1 = flips[i];
            }
            if (last1 == (i + 1)) {
                ++answer;
            }
        }
        return answer;
    }
};
*/
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int answer = 0;
        int last1 = 0;
        for (int i = 0; i != flips.size(); ++i) {
            last1 = max(last1, flips[i]);
            if (last1 == (i + 1)) {
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
