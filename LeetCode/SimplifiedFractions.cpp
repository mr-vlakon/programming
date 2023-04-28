class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> answer;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(i,j) == 1) {
                   answer.push_back(to_string(j) + '/' + to_string(i)); 
                }
            }
        }
        return answer;   
    }
};

int main() {
  
  
  
  return 0;  
}
