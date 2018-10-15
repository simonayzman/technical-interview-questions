// TODO: Keep a hash table of key/value pairs and also keep a priority queue (?) of key/timestamp pairs,
// with the timestamp representing either when it was first added or when it was last accessed via get.
class LRUCache {

    list<string> lruList;
    unordered_map<string, list::iterator> hashMap;
    unsigned int cacheSize;

    string get(string key) {
        list::iterator value = hashMap[key];

        return value;
    }

    void set(string key, string value) {
        pq.push(make_pair(key, getDateTime()));
        data
        if (pq.size() > 10) {
            pq.pop();
        }

    }

}