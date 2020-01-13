//
// Created by yehonatan on 12/01/2020.
//

// ****************************************************************************
// ***********    THIS CONTENT WAS MOVED TO FILE_CACHE_MANAGER.H    ***********
// ****************************************************************************

/*
#include "file_cache_manager.h"


using namespace std;

template<typename K, typename V>
void FileCacheManager<K,V>::insert(K key, V value) {

    hash_map_[key.toString()] = true;

    objectToFile(key, value);//save object in a file
}

//get an object and save a file with a name that contain key
template<typename  K, typename  V>
void FileCacheManager<K,V>::objectToFile(K & key, V & value) {
    fstream file;
    string file_name = key.toString();

    file.open(file_name.c_str(), ios::out|ios::binary);

    if(!file){
        throw "error in file opening";
    }

    file.write((char*)&value,sizeof(value));
    file.close();
}

template<typename K, typename V>
V FileCacheManager<K,V>::get(K & key) {

    if (exist(key.toString())) {
        return fileToObject(key.toString());
    }

    throw "key doesn't exist in map";
}

template<typename K, typename V>
bool FileCacheManager<K,V>::exist(K key) {
    return !(hash_map_.find(key) == hash_map_.end());
}

///////////////////////////////////////////////////////////////////////////////////
//next code is not ready
//needed to be done after writing some algorithms
//problem is naming the files in a certain order
///////////////////////////////////////////////////////////////////////////////////

//get a key of an item and return an appropriate item from a bin file
template<typename K, typename V>
V FileCacheManager<K,V>::fileToObject(K key) {
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
*/