class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int total = 0;
        for (const auto &e: bank) {
            auto cnt = count(e.cbegin(), e.cend(), '1');
            if (cnt == 0) {
                continue;
            } else {
                total += cnt * prev;
                prev = cnt;
            }
        }
        return total;
    }
};

int main() {
  
  
  return 0;  
}
