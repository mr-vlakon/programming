class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long count = 0;
        int finish = customers[0][0];
        for (int i = 0; i != customers.size(); ++i) {
            if (customers[i][0] >= finish) {
                count += customers[i][1];
                finish = customers[i][0] + customers[i][1];
            } else {
                count += finish - customers[i][0] + customers[i][1];
                finish = finish + customers[i][1];
            }
        }
        return static_cast<double>(count) / customers.size();
    }
};

int main() {
  
  
  
  return 0;  
}
