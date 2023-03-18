class Solution {
public:
    int distMoney(int money, int children) {
        vector<int> child(children, 1);
        money -= children;
        int answer = 0; 
        int prev = 0;   
        int cnt = 0;    
        for (int i = 0; i != child.size(); ++i) {
            prev = child[i];
            child[i] = min(8, money + child[i]);
            money -= (child[i] - prev);
            if (child[i] == 4) {
                child[i] = 3;
                money += 1;
            } else if (child[i] == 8) {
                ++answer;
            } else if (child[i] <= 0) {
                ++cnt;
            }
        }
        if (money > 0) {
            --answer;
        }
        if (cnt != 0) {
            return -1;
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
