/*assert_test.c*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef NDEBUG
	#define my_assert(expr)((void) ((expr) ? 0 : (__assert_fail (#expr, __FILE__, __LINE__, __func__),0)))
#endif


void foo(int num){
	assert(((num >= 0) && (num <= 100)));
	printf("foo : num = %d\n", num);
}

int main(int argc, char *argv[])
{
	int num;

	if(argc < 2){
		fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <=\n");
		exit(1);
	}

	num = atoi(argv[1]);
	foo(num);

}
