class SeatManager {
public:
    SeatManager(int n) {
        int i = 1;
        while (i <= n) {
            pq.push(i);
            ++i;
        }
    }
    
    int reserve() {
        auto small = pq.top();
        pq.pop();
        return small;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
    
private:
    priority_queue<int, deque<int>, greater<int>> pq;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main() {
  
  
  return 0;  
}
