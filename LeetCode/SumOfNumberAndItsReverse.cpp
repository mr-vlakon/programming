class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if (num == 0) return true;
        int i = 1;
        int sum = 0;
        int rev = 0;
        while (i < num) {
            string s = to_string(i);
            reverse(s.begin(), s.end());
            rev = stoi(s);
            sum = rev + i;
            if (sum == num)
                return true;            
            ++i;
        }
        return false;
    }    
};

int main() {
  
  
  return 0;  
}
