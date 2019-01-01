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
 * File : type.h
 */

#ifndef _LDEV_TYPE_
#define _LDEV_TYPE_
#include <stdlib.h>

struct _ltype_t {
    /*
     * The size of type
     */
    size_t _size;
    
    /*
     * The constructor and destructor of type
     */
    void* (*_constructor)();
    void (*_destructor)(void*);
    
    /*
     * The function to clone the object
     */
    void* (*_clone)(void*);
};

typedef struct _ltype_t ltype_t;

static void *ltype_instantiate(ltype_t *type)
{return type->_constructor();}

#endif
