class MyHashMap {
private:
    static const int SIZE = 1000001; // Large enough size to avoid collisions
    int map[SIZE];

public:
    MyHashMap() {
        // Initialize all elements with -1, indicating no mapping
        fill(map, map + SIZE, -1);
    }
    
    void put(int key, int value) {
        map[key] = value; // Insert or update the value for the given key
    }
    
    int get(int key) {
        return map[key]; // Return the value mapped to the key or -1 if not present
    }
    
    void remove(int key) {
        map[key] = -1; // Reset the key's value to -1, indicating removal
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
