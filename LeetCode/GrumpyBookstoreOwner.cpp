class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int tmp = 0;
        for (int i = 0; i != customers.size(); ++i) {
            if (grumpy[i] == 0) {
                sum += customers[i];            
            }
        }
        int answer = 0;
        for (int i = 0; i != minutes; ++i) {
            if (grumpy[i] == 1) {
                tmp += customers[i];
            }
        }
        answer = max(answer, tmp + sum);
        for (int i = 1; i < static_cast<int>(customers.size()) - minutes + 1; ++i) {
            if (grumpy[i - 1] == 1) {
                tmp -= customers[i - 1];
            }
            if (grumpy[i + minutes - 1] == 1) {
                tmp += customers[i + minutes - 1];
            }
            answer = max(answer, sum + tmp);
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
