class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int answer = 0;
        while (true) {
            for (int i = 0; i != tickets.size(); ++i){
                if (tickets[i] != 0) {
                    --tickets[i];
                    ++answer;
                }
                if (i == k && tickets[i] == 0)
                    return answer;
            }
        }
        return 0;
    }
};

int main() {
  
  
  return 0;  
}
