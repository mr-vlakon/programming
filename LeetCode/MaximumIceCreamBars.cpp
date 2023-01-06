class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int answer = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i != costs.size(); ++i) {
            if (coins < costs[i]) {
                break;
            } else {
                coins -= costs[i];
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
