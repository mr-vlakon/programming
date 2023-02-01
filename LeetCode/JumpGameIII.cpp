class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> us;
        queue<int> q;
        q.push(start);
        us.insert(start);
        while (!q.empty()) {
            auto top = q.front();
            if (arr[top] == 0) return true;
            q.pop();
            if ((top + arr[top]) < arr.size()) {
                if (us.find(top + arr[top]) == us.cend())
                    q.push(top + arr[top]);
                us.insert(top + arr[top]);
            }
            if (((top - arr[top]) >= 0) && ((top - arr[top]) < arr.size())) {
                if (us.find(top - arr[top]) == us.cend())
                    q.push(top - arr[top]);
                us.insert(top - arr[top]);
            } 
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
