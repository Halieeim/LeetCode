class LRUCache {
public:
    unordered_map<int,int> cache;
    vector<int> vec;
    int size, capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        auto it = find(vec.begin(), vec.end(), key);
        if(it != vec.end()){
            int v = cache[key];
            vec.erase(it);
            vec.push_back(key);
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = find(vec.begin(), vec.end(), key);
        if(it != vec.end()){
            cache[key] = value;
            vec.erase(it);
            vec.push_back(key);
        }
        else{
            if(vec.size() == this->capacity){
                int lu = vec.front();
                vec.erase(vec.begin());
                cache.erase(lu);
            }
            cache[key] = value;
            vec.push_back(key);
        }
    }
};