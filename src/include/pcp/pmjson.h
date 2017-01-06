/*
 * Copyright (c) 2015-2016 Red Hat.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * Javascript Object Notation metric value extraction (libpcp_web)
 */
#ifndef PCP_PMJSON_H
#define PCP_PMJSON_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum json_flags {
    pmjson_flag_bitfield = (1<<0),
    pmjson_flag_boolean  = (1<<1),
    pmjson_flag_s32      = (1<<2),
    pmjson_flag_u32      = (1<<3),
    pmjson_flag_s64      = (1<<4),
    pmjson_flag_u64      = (1<<5),
    pmjson_flag_float    = (1<<6),
    pmjson_flag_double   = (1<<7),
} json_flags;

typedef struct json_metric_desc {
    char          *json_pointer;
    json_flags    flags;
    int           num_values;
    pmAtomValue   values;
    char          *dom;
} json_metric_desc;

typedef void (*buffer_func)(char*, int*, void*);

PCP_CALL extern int pmjsonInit(int fd, json_metric_desc *, int);
PCP_CALL extern int pmjsonInitIndom(int fd, json_metric_desc *, int, pmInDom);
PCP_CALL extern int pmjsonInitIterable(json_metric_desc *, int, pmInDom, void(*)(char*, int*, void*), void* json_input);


#ifdef __cplusplus
}
#endif

#endif /* PCP_PMJSON_H */
