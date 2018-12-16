#include <stdio.h>
#include "../ldev/string.h"
int string_main(){
	lstring_t *str = lstring_cstr("helohello helllo world");
	lstring_kmp_cache_t *cache = lstring_kmp_cache(str);
	printf("%s",lstring_find(str, lstring_cstr("hello"), NULL));
	_lstring_kmp_cache(cache);
	_lstring(str);
	return 0;
}
