class Solution {
public:
    void binary(const vector<int> &nums, int &left, int &right) {
        if (left > right) {
            return;
        }
        tmp = 0;
        mid = (left + right) / 2;
        for (const auto &e: nums) {
            tmp += ceil(static_cast<double>(e) / static_cast<double>(mid + 1));
        }
        if (tmp <= th) {
            answer = min(answer, mid + 1);
            right = mid - 1;
            binary(nums, left, right); 
        } else {
            left = mid  + 1; 
            binary(nums, left, right);        
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        th = h;
        int maxV = *max_element(piles.cbegin(), piles.cend()) - 1;
        int left = 0;
        binary(piles, left, maxV);
        return answer;
    }
private:
    int mid = 0;
    int th = 0;
    long long tmp = 0;
    int answer = 1000000001;
};

int main() {

  
  
  return 0;  
}
