class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> bits(32, 0);
        int k = 0;
        for (const auto &e: nums) {
            k = 0;
            while (e >= (1 << k)) {
                if ((e & (1 << k )) != 0) {
                    bits[k]++;
                }
                ++k;
            }
        }
        int answer = 0;
        int offset = 0;
        bool flag = false;
        for (int i = bits.size() - 1; i >= 0; --i) {
            if (!flag) {
                offset = i * ((bits[i] != 0) ? 1 : 0);
                if (offset != 0) {
                    answer += offset;
                    flag = true;
                }
            }
            answer += bits[i];
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
