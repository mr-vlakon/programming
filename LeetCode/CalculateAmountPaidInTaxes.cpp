class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double answer = 0;
        int prev = 0;
        for (int i = 0; i != brackets.size(); ++i) {
            if (income >= prev) {
                if (income > brackets[i][0]) {
                answer += (brackets[i][0] - prev) * 
                    static_cast<double>(brackets[i][1]) / 100.00; 
                } else {
                answer += (income - prev) * 
                    static_cast<double>(brackets[i][1]) / 100.00; }             
            }
            prev = brackets[i][0];
        }
        return answer;
    }
};

int main() {
  
  
  return 0; 
}
