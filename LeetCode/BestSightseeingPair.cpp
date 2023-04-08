class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxV = max(values[0], values[1] + 1);
        int maxF = values[0] + values[1] - 1;
        for (int i = 2; i != values.size(); ++i) {
            maxF = max(maxF, values[i] - i + maxV);
            maxV = max(maxV, values[i] + i);
        }
        return maxF;
    }
};

int main() {
  
  
  
  
  return 0;  
}
