// 
// Created by Insomnia on 2019/4/8.
//

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {}

    int get(int key) {
        if (kv.count(key) == 0) {
            return -1;
        }
        bringToHead(key);
        return kv[key];
    }

    void put(int key, int value) {
        if (kv.size() == cap && kv.count(key) == 0) {
           trimTail();
        }

        bringToHead(key);
        kv[key] = value;
    }

private:
    int cap;
    list<int> lru;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int, int> kv;

    void bringToHead(int key) {
        if (kv.count(key)) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }

    void trimTail() {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }
};

int main() {
    return  0;
}