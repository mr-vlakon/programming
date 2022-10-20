class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = accumulate(salary.cbegin() + 1, salary.cend() - 1, 0.0);
        return sum / (salary.size() - 2);
    }
};

int main() {
  
  
  return 0;  
}
