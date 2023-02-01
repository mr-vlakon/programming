
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int> q;
        unordered_set<int> us;
        for (const auto &e: rooms[0]) {
            us.insert(e);
            q.push(e);
        }   
        us.insert(0);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            for (const auto &e: rooms[top]) {
                if (us.find(e) == us.cend()) {    
                    q.push(e);
                }
                us.insert(e);
            }
        }
        return us.size() == rooms.size();
    }
};

int main() {
  
  
  
  return 0;  
}
