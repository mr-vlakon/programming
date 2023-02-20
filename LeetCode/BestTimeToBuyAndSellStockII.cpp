class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int pos = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < prices[i - 1]) {
                answer += prices[i - 1] - prices[pos];
                pos = i;
            } 
        }
        if (pos != (prices.size() - 1)) {
            answer += prices.back() - prices[pos];
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
