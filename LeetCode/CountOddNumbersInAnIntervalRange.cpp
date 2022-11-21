class Solution {
public:
    int countOdds(int low, int high) {
        int answer = 0;
        if (low % 2 == 1) ++answer;
        if (high % 2 == 1) ++answer;
        return (high - low - answer) / 2 + answer;
    }
};

int main() {
  
    
  return 0;  
}
