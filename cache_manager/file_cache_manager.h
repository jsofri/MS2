//
// Created by yehonatan on 12/01/2020.
//

#ifndef FILE_CACHE_MANAGER_H
#define FILE_CACHE_MANAGER_H
#define MAX_FILE_SIZE 4096

#include "cache_manager.h"
#include "unordered_map"
#include <fstream>
#include <dirent.h>
#include <mutex>
#include "iostream"
#include "cstring"

using namespace std;

template<typename K, typename V>
class FileCacheManager : public CacheManager<K, V> {
public:
    FileCacheManager<K, V>() {
        pushFilesToMap();
    }

    /*FileCacheManager<K,V>(FileCacheManager & fcm) {
        pushFilesToMap();
    }*/

    //FileCacheManager(const FileCacheManager&) = delete;

    void insert(K key, V value) {
        lock_guard<mutex> lock(locker_);
        hash_map_[key -> toHash()] = true;

        objectToFile(key, value);//save object in a file
    }

    V get(K key) {

        if (exist(key)) {
            return fileToObject(key);
        }

        throw "key doesn't exist in map";
    }

    bool exist(K key) {
        lock_guard<mutex> lock(locker_);

        unsigned long k = key -> toHash();
        return !(hash_map_.find(k) == hash_map_.end());
    }

    FileCacheManager<K, V>& operator=(FileCacheManager const& other) {
        return *this;
    }

    FileCacheManager<K, V>(FileCacheManager const& other) {
        hash_map_ = other.hash_map_;
    }

private:
    void pushFilesToMap() {
        DIR *dir;
        struct dirent *ent;
        if ((dir = opendir(CACHE_DIRECTORY)) != NULL) {
            // print all the files and directories within directory
            while ((ent = readdir (dir)) != NULL) {
                // skip `.` and `...`
                if (ent -> d_name[0] != '.') {
                    hash_map_[stol(ent->d_name)] = true;
                }
            }
            closedir (dir);
        } else {
            // could not open directory
            perror ("Error opening `cached_solutions` dir");
            exit(1);
        }
    }

    void objectToFile(K & key, V & value) {
        fstream file;
        string file_name = CACHE_DIRECTORY + to_string(key -> toHash());
        char zibi[MAX_FILE_SIZE] = {0};
        strcpy(zibi, value.c_str());

        file.open(file_name.c_str(), ios::out);

        if(!file){
            throw "error in file opening";
        }

        file.write((char*)&zibi, value.length());
        file.close();
    }

    string fileToObject(K key) {
        string file_name;
        fstream file;
        string object, temp;

        file_name = string(CACHE_DIRECTORY) + to_string(key -> toHash());

        file.open(file_name.c_str() ,ios::in);
        if(!file){
            throw "Error in file opening";
        }

        while (file >> temp) {
            object += temp;
        }
        file.close();

        return object;
    }

    std::unordered_map<unsigned long, bool> hash_map_;
    mutable mutex locker_;
};

#endif //FILE_CACHE_MANAGER_H
