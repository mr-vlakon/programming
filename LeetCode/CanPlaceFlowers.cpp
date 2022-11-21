class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        for (int i = 0; i != flowerbed.size(); ++i) {
            if (flowerbed[i] == 0 && ((i - 1 >= 0) ? (flowerbed[i - 1] == 0) : true) && ((i + 1 < flowerbed.size()) ? (flowerbed[i + 1] == 0) : true)) {
                ++cnt;
                flowerbed[i] = 1;
            }
        }
        return cnt >= n;
    }
};

int main() {
  
  
  
  return 0;  
}
