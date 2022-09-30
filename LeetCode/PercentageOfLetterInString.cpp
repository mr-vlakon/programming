class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (const auto &e: s) {
            if (e == letter)
                ++cnt;
        }
        
        return (cnt * 100)/ s.size();
    }
};

int main() {
  
  
  return 0;  
}
