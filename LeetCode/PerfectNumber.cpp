class Solution {
public:
    bool checkPerfectNumber(int num) {
        int result = 0;
        int i = 1;
        bool status = false;
        while (i <= num  / 2) {
            if(num % i == 0)
                result += i;
            i += 1;
        }
        return result == num;
    }
};

int main() {
  
  return 0;  
}
