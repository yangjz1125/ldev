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

typedef struct _lstring_t lstring_t;
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
static inline size_t lstring_length(lstring_t *str){
	return str->_length;
}
#endif
