#include <stdio.h>
#include "../ldev/string.h"
int string_main(){
	lstring_t *str = lstring_cstr("hellohello helllo world");
	lstring_replace_cstr(str, "he", "HEE");
	printf("%s", str->_data);
	_lstring(str);
	return 0;
}
