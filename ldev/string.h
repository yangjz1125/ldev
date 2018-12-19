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
 * File : string.h
 */

#ifndef _LDEV_STRING_
#define _LDEV_STRING_
#include <stdlib.h>
struct _lstring_t {
	/*
	 * string data.
	 */
	char *_data;
	/*
	 * _length: string length
	 * _bufsize : string bufsize
	 */
	size_t _length, _bufsize;
};

struct _lstring_kmp_cache_t{
    /*
     * string information cache
     */
    size_t *_cache;
};

typedef struct _lstring_t lstring_t;
typedef struct _lstring_kmp_cache_t lstring_kmp_cache_t;
/*
 * get new lstring_t
 */
lstring_t* lstring(void);

/*
 * free lstring_t
 */
void _lstring(lstring_t *str);

/*
 * clone lstring_t
 */
lstring_t* lstring_clone(const lstring_t *str);

/*
 * cast char to lstring_t
 */
lstring_t* lstring_char(char c);

/*
 * cast c string to lstring_t
 */
lstring_t* lstring_cstr(const char *cstr);

/*
 * clear lstring_t
 */
void lstring_clear(lstring_t *str);

/*
 * squash lstring_t
 */
void lstring_squash(lstring_t *str);

/*
 * get lstring_t minimum range.
 */
static inline size_t lstring_range(lstring_t *str)
{return str->_bufsize-1;}

/*
 * set lstring_t minium range.
 */
void lstring_set_range(lstring_t *str, size_t range);

/*
 * append another lstring_t
 */
void lstring_append(lstring_t *str, lstring_t *another);

/*
 * append another c string 
 */
void lstring_append_cstr(lstring_t *str, const char *another);

/*
 * append another char
 */
void lstring_append_char(lstring_t *str, char c);

/*
 * get the length of str
 */
static inline size_t lstring_length(lstring_t *str)
{return str->_length;}

/*
 * get the lstring_t's length
 */
static inline char* lstring_data(lstring_t *str)
{return str->_data;}

/*
 * Iterators
 * Please use lstring_iter_t as a pointer.
 */
typedef char* lstring_iter_t;
typedef const char* lstring_citer_t;

static inline lstring_iter_t lstring_begin(lstring_t *str)
{return str->_data;}

static inline lstring_iter_t lstring_end(lstring_t *str)
{return str->_data+str->_length;}

/*
 * replace a to b.
 */
void lstring_replace_char(lstring_t *str, char a, char b);
void lstring_replace_cstr(lstring_t *str, const char *a, const char *b);
void lstring_replace(lstring_t *str, const lstring_t *a, const lstring_t *b);

/*
 * find a in b
 */
lstring_iter_t lstring_find(lstring_t *str, lstring_t *par, lstring_kmp_cache_t *cache);
lstring_iter_t lstring_find_from(lstring_t *str, lstring_t *par, size_t index, lstring_kmp_cache_t *cache);

/*
 * get the KMP information cache of lstring
 */
lstring_kmp_cache_t *lstring_kmp_cache(lstring_t *str);

/*
 * free the KMP information cache of lstring
 */
void _lstring_kmp_cache(lstring_kmp_cache_t *cache);

#endif
