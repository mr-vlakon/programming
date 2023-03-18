class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() != b.size()) {
            return max(static_cast<int>(a.size()),static_cast<int>(b.size()));
        }
        if (a == b) {
            return -1;
        }
        return a.size();
    }
};

int main() {
  
  
  return 0;  
}
