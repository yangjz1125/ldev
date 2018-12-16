/* LDev library 
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Copyright (c) 2018, YangJZ.
 * Author: YangJZ
 * File : string_kmp.c
 */

#include "string.h"
#include <string.h>
#include <stdlib.h>

lstring_kmp_cache_t *lstring_kmp_cache(lstring_t *str){
    lstring_kmp_cache_t *cache = (lstring_kmp_cache_t*)malloc(sizeof(lstring_kmp_cache_t));
    cache->_cache = (size_t*)malloc(sizeof(size_t) * str->_length+1);
    size_t k = 0;
    cache->_cache[0] = 0;
    for(size_t i = 1; i < str->_length; ++i){
        while(k > 0 && str->_data[k] != str->_data[i]){
            k = cache->_cache[k-1];
        }
        ++k;
        if(str->_data[k] != str->_data[i]) cache->_cache[i] = k;
        else cache->_cache[i] = 0;
    }
    return cache;
}

void _lstring_kmp_cache(lstring_kmp_cache_t *cache){
    free(cache->_cache);
    free(cache);
}

lstring_iter_t lstring_find(lstring_t *str, lstring_t *par, lstring_kmp_cache_t *cache){
    if(cache == NULL) return strstr(str->_data, par->_data);
    else 
        for(size_t i = 0, j = 0; i < str->_length; ++i){
            while(j > 0 && str->_data[i] != par->_data[j]) j = cache->_cache[j-1];
            if(str->_data[i] != par->_data[j]) ++j;
            if(j == par->_length) return str->_data + i - j;
        }
    return lstring_end(str);
}