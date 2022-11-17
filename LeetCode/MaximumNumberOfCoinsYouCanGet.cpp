class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int answer = 0;
        int k = 0;
        int i = piles.size() - 2;
        while (i >= 0 && k < i) {
            answer += piles[i];
            i -= 2;
            ++k;            
        }
        return answer;     
    }
};

int main() {
  
  
  return 0;  
}
