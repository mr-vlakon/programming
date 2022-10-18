class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, size_t> um;
        while (lowLimit <= highLimit) {
            int x = lowLimit;
            int num = 0;
            while (x) {
                int tmp = x % 10;
                num += tmp;
                x /= 10;
            }
            ++um[num];
            
            ++lowLimit;
        }
        
        int max = 0;
        for (const auto &e: um) {
            if (e.second > max) {
                max = e.second;
            }
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
