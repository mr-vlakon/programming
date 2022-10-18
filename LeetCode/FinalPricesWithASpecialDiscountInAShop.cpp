class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int i = 0;
        vector<int> answer;
        while (i != prices.size() - 1) {
            auto it = find_if(prices.cbegin() + i + 1, prices.cend(), [=] (const int &x) {
               return prices[i] >= x; 
            });
            if (it == prices.cend()) {
                answer.push_back(prices[i]);
            } else {
                answer.push_back(prices[i] - *it);
            }
            
            ++i;
        }
        answer.push_back(prices.back());
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
