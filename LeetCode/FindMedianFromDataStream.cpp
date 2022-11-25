class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.size() == 0) {
            maxHeap.push(num);
        } else if (maxHeap.size() == 1 && minHeap.size() == 0) {
            if (num > maxHeap.top()) {
                minHeap.push(num);
            } else {
                auto top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
                maxHeap.push(num);
            }
        } else {     
            if (num <= minHeap.top()) {
                if (maxHeap.size() > minHeap.size()) {
                    auto top = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(top);
                    
                    if (maxHeap.top() > minHeap.top()) {
                        auto topMax = maxHeap.top();
                        maxHeap.pop();
                        auto topMin = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(topMin);
                        minHeap.push(topMax);        
                    }
                    
                } else {
                    maxHeap.push(num);
                    if (maxHeap.top() > minHeap.top()) {
                        auto topMax = maxHeap.top();
                        maxHeap.pop();
                        auto topMin = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(topMin);
                        minHeap.push(topMax);        
                    }

                }
            } else {
                if (maxHeap.size() < minHeap.size()) {
                    auto top = minHeap.top();
                    minHeap.pop();
                    minHeap.push(num);
                    maxHeap.push(top);
                    if (maxHeap.top() > minHeap.top()) {
                        auto topMax = maxHeap.top();
                        maxHeap.pop();
                        auto topMin = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(topMin);
                        minHeap.push(topMax);        
                    }

                } else {
                    minHeap.push(num);
                    if (maxHeap.top() > minHeap.top()) {
                        auto topMax = maxHeap.top();
                        maxHeap.pop();
                        auto topMin = minHeap.top();
                        minHeap.pop();
                        maxHeap.push(topMin);
                        minHeap.push(topMax);        
                    }

                }
            }            
        }   
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
        
    }
private:
    priority_queue<double> maxHeap;
    priority_queue<double, deque<double>, greater<double> > minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  
  
  
  return 0;  
}
