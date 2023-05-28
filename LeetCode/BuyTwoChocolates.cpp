class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int answer = money;
        answer -= prices[0];
        answer -= prices[1];
        if (answer >= 0)
            return answer;
        else
            return money;
    }
};

int main() {
  
  
  
  return 0;  
}
