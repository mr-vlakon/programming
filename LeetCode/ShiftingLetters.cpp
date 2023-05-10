class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long sum = accumulate(shifts.cbegin(), shifts.cend(), 0LL);
        for (int i = 0; i != shifts.size(); ++i) {
            s[i] = (sum + (s[i] - 'a')) % 26 + 'a';
            sum -= shifts[i];
        }
        return s;
    }
};

int main() {
  
  
  
  return 0;  
}
