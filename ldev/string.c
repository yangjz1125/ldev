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
 * File : string.c
 */

#include "string.h"
#include <string.h>
#include <stdlib.h>

lstring_t* lstring(void){
	lstring_t *str = (lstring_t*)malloc(sizeof(lstring_t));
	str->_data = NULL;
	str->_bufsize = str->_length = 0;
	return str;
}

void _lstring(lstring_t *str){
	free(str->_data);
	free(str);
}

lstring_t* lstring_clone(const lstring_t *str){
	lstring_t *another = (lstring_t*)malloc(sizeof(lstring_t));
	another->_bufsize = str->_bufsize;
	another->_length = str->_length;
	another->_data = (char*)malloc(another->_bufsize);
	strcpy(another->_data, str->_data);
	return another;
}

lstring_t* lstring_char(char c){
	lstring_t *str = (lstring_t*)malloc(sizeof(lstring_t));
	str->_bufsize = 4;
	str->_length = 1;
	str->_data = (char*)malloc(str->_bufsize);
	str->_data[0] = c;
	str->_data[1] = '\0';
	return str;
}

lstring_t* lstring_cstr(const char *cstr){
	lstring_t *str = (lstring_t*)malloc(sizeof(lstring_t));
	str->_length = strlen(cstr);
	str->_bufsize = (str->_length+1) * 2;
	str->_data = (char*)malloc(str->_bufsize);
	strcpy(str->_data, cstr);
	return str;
}

void lstring_clear(lstring_t *str){
	str->_length = 0;
}

void lstring_squash(lstring_t *str){
	if((str->_bufsize = str->_length) == 0){
	        free(str->_data);
		str->_data = NULL;
	} else {
		str->_data = realloc(str->_data, str->_bufsize);
	}
}

void lstring_set_range(lstring_t *str, size_t range){
	if(range < str->_length) return;
	if(!range) {
		str->_bufsize = 0, free(str->_data), str->_data = NULL;
		return;
	}
	str->_bufsize = range+1;
	str->_data = realloc(str->_data, str->_bufsize);
}

void lstring_append(lstring_t *str,lstring_t *another){
	size_t l = str->_length + another->_length;
        if(lstring_range(str) < l){
		lstring_set_range(str, 2*l+1);
	}
	strcpy(str->_data+str->_length, another->_data);
}

void lstring_append_cstr(lstring_t *str,const char *another){
	size_t l = str->_length + strlen(another);
        if(lstring_range(str) < l){
		lstring_set_range(str, 2*l+1);
	}
	strcpy(str->_data+str->_length, another);
}

void lstring_append_char(lstring_t *str,char c){
	++str->_length;
	if(lstring_range(str) < str->_length){
		lstring_set_range(str, 2*str->_length+1);
	}
	str->_data[str->_length] = '\0', str->_data[str->_length-1] = c;
}

