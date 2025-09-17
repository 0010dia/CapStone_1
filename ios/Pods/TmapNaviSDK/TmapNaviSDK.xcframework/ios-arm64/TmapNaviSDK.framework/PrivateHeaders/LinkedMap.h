#ifndef GIT_ANDROID_TMAP_MAIN_LINKEDMAP_H
#define GIT_ANDROID_TMAP_MAIN_LINKEDMAP_H

#include <iostream>
#include<map>
#include <vector>
#include <mutex>

using namespace std;

/**
 * A map class that has an input order.
 * Search time is n * log(n) in Map.
 *
 * @tparam K key type
 * @tparam V value type
 */

template <typename K, typename V>
class LinkedMap
{
private:
    vector<K> keyList;
    vector<V> valueList;

    map<K, V> treeMap;
    std::mutex _mutex;

public:
    bool Add(K key, V& value)
    {
        std::lock_guard<std::mutex> lk(this->_mutex);

        typename std::map<K, V>::iterator it = treeMap.find(key);
        if (it != treeMap.end())
        {
            // 기존 데이터를 변경한다.
            memcpy(&(it->second), &value, sizeof(V));
        }
        else
        {
            keyList.push_back(key);
            valueList.push_back(value);
            treeMap.insert(std::pair<K, V>(key, value));
        }

        return true;
    }

    V* GetAtPtr(const K& key)
    {
        std::lock_guard<std::mutex> lk(this->_mutex);
        return treeMap.find(key)->second;
    }

    V* GetBuffer() {
        std::lock_guard<std::mutex> lk(this->_mutex);
        return valueList.data();
    }

    int Size() {
        std::lock_guard<std::mutex> lk(this->_mutex);
        return valueList.size();
    }

    bool Remove(int remainSize)
    {
        std::lock_guard<std::mutex> lk(this->_mutex);
        int count = keyList.size() - remainSize;
        if (count <= 0) {
            return false;
        }
        keyList.erase(keyList.begin(), keyList.begin() + count);
        valueList.erase(valueList.begin(), valueList.begin() + count);
        treeMap.clear();

        for (int i = 0; i < keyList.size(); i++)
        {
            treeMap.insert(std::pair<K, V>(keyList.at(i), valueList.at(i)));
        }

        return true;
    }

    V* GetLast()
    {
        std::lock_guard<std::mutex> lk(this->_mutex);
        if (valueList.size() > 0)
        {
            return &(valueList.back());

        }

        return nullptr;
    }

    bool ContainsKey(K key)
    {
        std::lock_guard<std::mutex> lk(this->_mutex);
        if (treeMap.size() > 0)
        {
            typename std::map<K, V>::iterator it = treeMap.find(key);
            return (it != treeMap.end());
        }

        return false;
    }
};


#endif //GIT_ANDROID_TMAP_MAIN_LINKEDMAP_H
