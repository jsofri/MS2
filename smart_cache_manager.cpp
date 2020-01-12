//
// Created by yehonatan on 12/01/2020.
//

#include "smart_cache_manager.h"

using namespace server_side;
using namespace std;

template<typename K, typename V>
void SmartCacheManager<K,V>::insert(K key, V value) {

    hash_map_[key] = value;

    objectToFile(key, value);//save object in a file
}

//get an object and save a file with a name that contain key
template<typename  K, typename  V>
void SmartCacheManager<K,V>::objectToFile(K key, V value) {
    fstream file;
    string file_string;
    const char* file_name;

    file_name = getFileName(key, file_string);

    file.open(file_name,ios::out|ios::binary);
    if(!file){
        throw "error in file opening";
    }

    file.write((char*)&value,sizeof(value));
    file.close();
}

template<typename K, typename V>
V SmartCacheManager<K,V>::get(K key){
    V item;

    if (!isInMap(key)) {
        item = fileToObject(key);
    }
    else {
        item = hash_map_[key].second;
    }

    enterToCache(key, item);

    return hash_map_[key].second;
}

template<typename K, typename V>
bool SmartCacheManager<K,V>::exist(K key) {
    return !(hash_map_.find(key) == hash_map_.end());
}

template<typename K, typename V>
SmartCacheManager<K, V>::~SmartCacheManager() {

}

///////////////////////////////////////////////////////////////////////////////////
//next code is not ready
//needed to be done after writing some algorithms
//problem is naming the files in a certain order
///////////////////////////////////////////////////////////////////////////////////

//set file name to key+class_name+".dat" - binary file name
template<typename K, typename V>
const char* SmartCacheManager<K,V>::getFileName(K & key, string & file_string) {
    file_string = key.append(T::class_name);
    file_string = file_string.append(".dat");

    return file_string.c_str();
}

//get a key of an item and return an appropriate item from a bin file
template<typename K, typename V>
V SmartCacheManager<K,V>::fileToObject(K key) {
        string file_string;
        const char* file_name;
        fstream file;
        T object;

        file_name = getFileName(key, file_string);

        file.open(file_name,ios::in|ios::binary);
        if(!file){
            throw "Error in file opening";
        }

        if(!file.read((char*)&object,sizeof(object))){
            throw "Error in file opening";
        }

        file.close();

        return object;
}
