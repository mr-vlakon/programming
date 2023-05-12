class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int answer = 0;
        int tmp = 0;
        for (int i = cardPoints.size() - k; i != cardPoints.size(); ++i) {
            tmp += cardPoints[i];
        }
        answer = max(answer, tmp);
        for (int i = cardPoints.size() - k + 1; i <= cardPoints.size(); ++i) {
            tmp -= cardPoints[i - 1];
            tmp += cardPoints[(i + k - 1) % cardPoints.size()];
            answer = max(answer, tmp);
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
