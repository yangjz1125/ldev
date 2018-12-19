#include <stdio.h>
#include "../ldev/string.h"
#include "tests.h"
int string_main(){
	lstring_t *str = lstring_cstr("helohello hello world");
	lstring_kmp_cache_t *cache = lstring_kmp_cache(str);
	printf("%s",lstring_find_from(str, lstring_cstr("hello"), 5, NULL));
	_lstring_kmp_cache(cache);
	_lstring(str);
	return 0;
}
