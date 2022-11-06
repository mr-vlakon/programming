class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost = 0;
        priority_queue<int, deque<int>, greater<int>> pq1;
        priority_queue<int, deque<int>, greater<int>> pq2;
        if ((candidates * 2) < costs.size()) {
            for (int i = 0; i != candidates; ++i) {
                pq1.push(costs[i]);
            }
            for (int i = costs.size() - candidates; i != costs.size(); ++i) {
                pq2.push(costs[i]);
            }
            
            deque<int> st(costs.cbegin() + candidates, costs.cbegin() + (costs.size() - candidates));
            
            int i = 0;
            int l = candidates;
            int p = costs.size() - candidates - 1;
            while (i < k) {
                auto top1 = pq1.top();
                auto top2 = pq2.top();
                if (top1 <= top2) {
                    cost += top1;
                    pq1.pop();
                    if (!st.empty()) {
                        auto tp = st.front();
                        pq1.push(tp);
                        st.pop_front();
                    } else {
                        ++i;
                        if (i >= k) {
                            break;
                        }
                        
                        priority_queue<int, deque<int>, greater<int>> res = pq1;
                        
                        while (!pq2.empty()) {
                            auto tq = pq2.top();
                            res.push(tq);
                            pq2.pop();
                        }
                        
                        while (i < k) {
                            auto tmp = res.top();
                            cost += tmp;
                            res.pop();
                            ++i;
                            
                        }
                        break;
                    }
                } else {
                    cost += top2;
                    pq2.pop();
                    if (!st.empty()) {
                        auto tp = st.back();
                        pq2.push(tp);
                        st.pop_back();
                    } else {
                        ++i;
                        if (i >= k) {
                            break;
                        }
                        
                        priority_queue<int, deque<int>, greater<int>> res = pq1;
                        
                        while (!pq2.empty()) {
                            auto tq = pq2.top();
                            res.push(tq);
                            pq2.pop();
                        }
                        
                        while (i < k) {
                            auto tmp = res.top();
                            cost += tmp;
                            res.pop();
                            ++i;   
                        }
                        break;
                    }
                }
                ++i;
            }
        } else {
            priority_queue<int, deque<int>, greater<int>> pq(costs.cbegin(), costs.cend());
            
            int i = 0;
            while (i != k) {
                auto top = pq.top();
                cost += top;
                pq.pop();
                ++i;
            }
            
        }
        return cost;
        
    }
};

int main() {
  
  
  
  return 0;  
}
