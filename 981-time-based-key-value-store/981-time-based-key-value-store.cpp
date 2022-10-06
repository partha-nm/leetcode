class TimeMap {
    map<string,vector<pair<int,string>>> keyValStore;
public:
    TimeMap() {
        this->keyValStore = map<string,vector<pair<int,string>>>();
    }
    
    void set(string key, string value, int timestamp) {
        keyValStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(keyValStore[key].size() == 0) return "";
        
        int n = keyValStore[key].size();
        int l = 0, r = n -1, mid = -1;
        
        while(l <= r){
            mid = (l+r)/2;
            if(keyValStore[key][mid].first <= timestamp) l = mid + 1;
            else r = mid - 1;
        }

        if(l == 0) return "";
        return keyValStore[key][l-1].second;
    }
};