class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        currOrder = kingName;
    }
    
    void birth(string parentName, string childName) {
        map_[parentName].push_back(childName);
    }    

    void death(string name) {
        deathCon.insert(name);
        return;
    }

    void Successor(vector<string> &v, const string &currentPerson) {
        it = map_.find(currentPerson);
        if (deathCon.find(currentPerson) == deathCon.cend()) {
            v.push_back(currentPerson);
        }
        if (it != map_.cend()) {
            for (const auto &e: map_[currentPerson]) {
                Successor(v, e);
            }
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> v;
        Successor(v, currOrder);
        return v;            
    }
private:
    unordered_map<string, vector<string>>::iterator it;
    unordered_set<string> deathCon;
    string currOrder;
    unordered_map<string, vector<string>> map_;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main() {
  
  
  
  
  return 0;  
}
