class Solution {
public:
    string removeDigit(string number, char digit) {
        int i = 0;
        string max;
        for (const auto &e: number) {
            string tmp = number;
            if (e == digit) {
                tmp.erase(tmp.cbegin() + i);
                if (tmp > max)
                    max = tmp;
            }
            ++i;
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
