class Solution {
public:
    int countDigits(int num) {
        int x = num;
        int answer = 0;
        while (x) {
            int tmp = x % 10;
            if (num % tmp == 0) ++answer;
            x /= 10;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
