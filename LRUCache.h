/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/


class LRUCache{
public:

    LRUCache(int capacity) {
        _capacity = capacity;
        _size = 0;
    }

    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;
        auto it = _map[key];
        _list.push_front(*it);
        _list.erase(it);
        it = _list.begin();
        _map[key] = it;
        return it->second; 
    }

    void set(int key, int value) {
        auto it = _map.find(key);
        if (it != _map.end()) {
           _map.erase(key);
            _list.erase(it->second);
            _size--;
        }
        else if (_size == _capacity) {
            _map.erase(_list.back().first);
            _list.pop_back();
            _size--;
        }
        _list.push_front(make_pair(key, value));
        _map[key] = _list.begin();
        _size++;
    }

    list<pair<int, int> > _list;
    unordered_map<int, list<pair<int, int>>::iterator> _map;
    int _size;
    int _capacity;
    
};