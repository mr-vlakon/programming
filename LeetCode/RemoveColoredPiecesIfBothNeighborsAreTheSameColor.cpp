class Solution {
public:
    bool winnerOfGame(string colors) {
        auto it = colors.cbegin();
        auto prev = it;
        auto size_A = 0;
        auto size_B = 0;
        while (it != colors.cend()) {
            it = find_if(it, colors.cend(), [=](const char &c) {
               return c != *it;
            });
            auto size = it - prev;
            if (*prev == 'A' && size >= 3) {
                size_A += size - 2;
            } else if (*prev == 'B' && size >= 3)
                size_B += size - 2;
            prev = it;
        }
        return size_A > size_B;   
    }
};

int main() {
  
  return 0;  
}
