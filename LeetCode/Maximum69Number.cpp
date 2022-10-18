class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (auto &e: s) {
            if (e == '6') {
                e = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
  
  
  return 0;  
}
