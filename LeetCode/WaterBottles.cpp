class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = numBottles;
        int empty = numBottles;
        int x = 1;
        while (x) {
            x = empty / numExchange;
            answer += x;
            int y = numExchange * x;  
            empty = empty - y + x;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
