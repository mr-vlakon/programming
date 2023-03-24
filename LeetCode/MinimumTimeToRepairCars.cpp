class Solution {
public:
    void binary(const vector<int> &ranks, long long &left, long long &right) {
        if (left > right) return;
        tmp = 0;
        mid = (left + right) / 2;
        for (const auto &e: ranks) {
            tmp += sqrt((mid + 1) / e); 
        }
        if (tmp >= cars_) {
            answer = min(answer, mid + 1);
            right = mid - 1;
            binary(ranks, left, right);
        } else {
            left = mid + 1;
            binary(ranks, left, right);
        }
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int minV = *min_element(ranks.cbegin(), ranks.cend());
        long long right = minV*static_cast<long long>(cars)*cars - 1;
        long long left = 0;
        cars_ = cars;
        binary(ranks, left, right);
        return answer;
    }
private:
    long long mid = 0;
    long long tmp = 0;
    int cars_ = 0;
    long long answer = 1000000000000000;
};

int main() {
  
  
  return 0;  
}
