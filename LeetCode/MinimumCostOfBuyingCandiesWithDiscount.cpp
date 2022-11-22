class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());
        int answer = 0;
        for (int i = 0; i < cost.size(); i += 3) {
            answer += cost[i];
            if (i + 1 < cost.size())
                answer += cost[i + 1];
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
