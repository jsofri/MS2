//
// Created by yehonatan on 09/01/2020.
//

#ifndef CACHE_MANAGER_H
#define CACHE_MANAGER_H

#define CACHE_DIRECTORY "cached_solutions/"

template <typename K, typename V>
class CacheManager {
    public:
        virtual void insert(K, V) = 0;
        virtual V get(K &) = 0;
        virtual bool exist(K) = 0;
};
#endif //CACHE_MANAGER_H
