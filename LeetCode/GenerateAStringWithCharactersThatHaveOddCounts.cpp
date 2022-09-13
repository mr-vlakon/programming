class Solution {
public:
    string generateTheString(int n) {
        if (n % 2 == 1) {
            return string(n, 'a');
        } else {
            string s(n - 1, 'a');
            s.push_back('b');
            return s;
        }
        return "";
    }
};

int main() {
  
  
  
  return 0;  
}
