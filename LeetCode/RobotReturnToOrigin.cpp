class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> initial = {0, 0};
        pair<int, int> fin = {0, 0};
        
        for (const auto &e: moves) {
            if (e == 'L') {
                --fin.first;
            }
            if (e == 'R') {
                ++fin.first;
            }
            if (e == 'U') {
                ++fin.second;
            }
            if (e == 'D') {
                --fin.second;
            }
            
        }
        
        return fin == initial;
    }
};

int main() {
  
  
  
  return 0;  
}
