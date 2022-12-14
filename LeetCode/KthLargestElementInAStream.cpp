class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        int i = 0;
        while (i < (static_cast<int>(nums.size()) - k) && i < nums.size()) {
            maxHeap.push(nums[i]);
            ++i;
        }
        while(i < nums.size()) {
            minHeap.push(nums[i]);
            ++i;
        }
        if (maxHeap.size() != 0) {
            while (minHeap.top() < maxHeap.top()) {
                auto topMin = minHeap.top();
                minHeap.pop();
                auto topMax = maxHeap.top();
                maxHeap.pop();
                minHeap.push(topMax);
                maxHeap.push(topMin);
            }
        }
    }
    
    int add(int val) {
        if (minHeap.size() == K) {
            maxHeap.push(val);
        } else {
            minHeap.push(val);
        }
        if (maxHeap.size() != 0) {
            while (minHeap.top() < maxHeap.top()) {
                auto topMin = minHeap.top();
                minHeap.pop();
                auto topMax = maxHeap.top();
                maxHeap.pop();
                minHeap.push(topMax);
                maxHeap.push(topMin);
            }
        }
        return minHeap.top();
    }
private:
    int K = 0;
    priority_queue<int> maxHeap;
    priority_queue<int, deque<int>, greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
  
  
  
  
  return 0;  
}
