class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        istringstream is(s);
        string ss;
        while (is >> ss) {
            ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
