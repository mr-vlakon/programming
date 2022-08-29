class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s = to_string(num);
        reverse(s.begin(), s.end());
        int x = stoi(s);
        s = to_string(x);
        reverse(s.begin(), s.end());
        x = stoi(s);
        return x == num;
    }
};

int main() {
  
  return 0; 
}
