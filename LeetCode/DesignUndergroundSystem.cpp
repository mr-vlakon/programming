class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        um[id] = stationName;
        hash[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        avg[um[id] + "-" + stationName] += t - hash[id];
        cnt[um[id] + "-" + stationName]++;
    }  
    double getAverageTime(string startStation, string endStation) {
        return static_cast<double>(avg[startStation + "-" +  endStation]) / cnt[startStation + "-" + endStation];
    }
private:
    unordered_map<int, string> um;
    unordered_map<int, int> hash;
    unordered_map<string, int> cnt;
    unordered_map<string, int> avg;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main() {
  
  
  return 0;  
}
