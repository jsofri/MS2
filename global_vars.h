//
// Created by rony on 21/01/2020.
//

#ifndef MS2_GLOBAL_VARS_H
#define MS2_GLOBAL_VARS_H

#include "objects/point.h"
#include "searchables/searchable.h"
#include "cache_manager/file_cache_manager.h"

extern FileCacheManager<Searchable<Point>, string> cache_manager_;

#endif //MS2_GLOBAL_VARS_H
