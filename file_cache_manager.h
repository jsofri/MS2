//
// Created by yehonatan on 12/01/2020.
//

#ifndef FILE_CACHE_MANAGER_H
#define FILE_CACHE_MANAGER_H


#include "cache_manager.h"
#include "unordered_map"
#include <fstream>
#include "iostream"
#include "cstring"

using namespace std;

template <typename K, typename V>
class FileCacheManager : public CacheManager<K, V> {
public:
    void insert(K key, V value) {

        hash_map_[key.toString()] = true;

        objectToFile(key, value);//save object in a file
    }

    void objectToFile(K & key, V & value) {
        fstream file;
        string file_name = key.toString();

        file.open(file_name.c_str(), ios::out|ios::binary);

        if(!file){
            throw "error in file opening";
        }

        file.write((char*)&value,sizeof(value));
        file.close();
    }

    V get(K & key) {

        if (exist(key)) {
            return fileToObject(key);
        }

        throw "key doesn't exist in map";
    }

    bool exist(K key) {
        unsigned long k = key.toString();
        return !(hash_map_.find(k) == hash_map_.end());
    }

    V fileToObject(K key) {
        string file_name;
        fstream file;
        V object;

        file_name = key.toString();

        file.open(file_name.c_str() ,ios::in|ios::binary);
        if(!file){
            throw "Error in file opening";
        }

        if(!file.read((char*)&object,sizeof(object))){
            throw "Error in file opening";
        }

        file.close();

        return object;
    }

private:
    std::unordered_map<unsigned long, bool> hash_map_;
};

#endif //FILE_CACHE_MANAGER_H
