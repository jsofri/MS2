//
// Created by yehonatan on 12/01/2020.
//

#ifndef SMART_CACHE_MANAGER_H
#define SMART_CACHE_MANAGER_H


#include "cache_manager.h"
#include "unordered_map"
#include <fstream>
#include "iostream"
#include "cstring"


namespace server_side {
    template <typename K, typename V>
    class SmartCacheManager :  public CacheManager<K, V> {
    public:
        void insert(K, V);
        void objectToFile(K, V);
        V get(K);
        bool exist(K);
        const char* getFileName(K &, std::string &);
        V fileToObject(K);
        ~SmartCacheManager();
    private:
        std::unordered_map<K, V> hash_map_;
    };
}


#endif //SMART_CACHE_MANAGER_H
