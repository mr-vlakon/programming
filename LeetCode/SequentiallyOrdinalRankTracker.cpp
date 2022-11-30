class CompMax { 
public:
	bool operator() (const pair<int, string> &lhs, const pair<int, string> &rhs) {
		return (lhs.first < rhs.first) ? true : (lhs.first > rhs.first) ? 
			false : (lhs.second > rhs.second) ? true : false;
	}
};

class CompMin { 
public:
	bool operator() (const pair<int, string> &lhs, const pair<int, string> &rhs) {
		return (lhs.first > rhs.first) ? true : (lhs.first < rhs.first) ? 
			false : (lhs.second < rhs.second) ? true : false;
	}
};

class SORTracker {
public:
    SORTracker() {
        
    }
    
    void add(string name, int score) {
        if (right.size() == 0) {
            left.push({score, name});
        } else {
            if (score <= right.top().first && name >= right.top().second) {
                left.push({score, name});
            } else {
                right.push({score, name});
                auto top = right.top();
                left.push(top);
                right.pop();
            }
        }
    }
    
    string get() {
        auto top = left.top();
        left.pop();
        right.push(top);
        return top.second;
    }
private:
    priority_queue<pair<int, string>, deque<pair<int, string>>, CompMax> left;
    priority_queue<pair<int, string>, deque<pair<int, string>>, CompMin> right;
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */

int main() {
  
  
  
  return 0;  
}
