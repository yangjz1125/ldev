#include <stdio.h>
#include "../src/string.h"
int string_main(){
	printf("%s", lstring_cstr("hello world")->_data);
	return 0;
}
