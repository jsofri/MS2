#ifndef _GLOBAL_VARS_H_
#define _GLOBAL_VARS_H_

#include "cache_manager/file_cache_manager.h"
#include "objects/point.h"
#include "searchables/searchable.h"

extern FileCacheManager<Searchable<Point>*, string> file_cache_manager;

#endif //_GLOBAL_VARS_H_
