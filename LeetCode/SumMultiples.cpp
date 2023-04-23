class Solution {
public:
    int sumOfMultiples(int n) {
        int i = 1;
        int answer = 0;
        while (i <= n) {
            if (((i % 3) == 0) || ((i % 5) == 0) || ((i % 7) == 0)) {
                answer += i;
            }
            ++i;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
