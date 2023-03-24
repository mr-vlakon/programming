class Solution {
public:
    void binary(const vector<int> &nums, int &left, int &right) {
        if (left > right) {
            return;
        }
        if (left < 0) {
            return;
        }
        tmp = 0;
        mid = (left + right) / 2;
        if (mid == 0) return;
        for (const auto &e: nums) {
            tmp += ceil(static_cast<double>(e) / static_cast<double>(mid));
        }
        if (tmp <= th) {
            answer = min(answer, mid);
            right = mid - 1;
            binary(nums, left, right); 
        } else {
            left = mid + 1;
            binary(nums, left, right);        
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        th = h;
        int maxV = *max_element(piles.cbegin(), piles.cend());
        int left = 0;
        binary(piles, left, maxV);
        mid = 1;
        tmp = 0;
        for (const auto &e: piles) {
            tmp += e;
        }
        if (tmp <= th) {
            answer = min(answer, 1);
        }
        return answer;
    }
private:
    int mid = 0;
    int th = 0;
    long long tmp = 0;
    int answer = 10000000000;
};

int main() {

  
  
  return 0;  
}
