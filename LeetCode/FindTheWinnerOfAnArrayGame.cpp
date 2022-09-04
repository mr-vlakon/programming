class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k >= arr.size()) return *max_element(arr.cbegin(), arr.cend());
        int cnt = 0;
        deque<int> deq(arr.cbegin(), arr.cend());
        while(true) {
            if (deq[0] > deq[1]) {
                while(deq[0] > deq[1]) {
                    deq.push_back(deq[1]);
                    deq.erase(deq.cbegin() + 1);
                    ++cnt;
                    if (cnt >= k)
                        return deq[0];
                    if (deq[0] <= deq[1]) {
                        cnt = 1;
                        break;
                    }
                } 
            } else if (deq[0] < deq[1]){
                cnt = 1;
            }
            if (cnt >= k)
                return deq[1];
            rotate(deq.begin(), deq.begin() + 1, deq.end());
        }
        return 0;
    }
};

int main() {
  
  
  return 0;  
}
