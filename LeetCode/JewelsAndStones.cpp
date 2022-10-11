class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        for (const auto &e: stones) {
            if (find(jewels.cbegin(), jewels.cend(), e) != jewels.cend())
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
