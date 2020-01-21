//
// Created by yehonatan on 21/01/2020.
//

#ifndef MS2__GLOBAL_VARS_H_
#define MS2__GLOBAL_VARS_H_

#include "cache_manager/file_cache_manager.h"
#include "objects/point.h"
#include "searchables/searchable.h"

extern FileCacheManager<Searchable<Point>*, string> file_cache_manager;

#endif //MS2__GLOBAL_VARS_H_
