#include <stdio.h>
#include "mytrans.h"

int main(int argc, char** argv) {
	printf("app works(name: %s, version: 3)\n", mytrans_proceed("zh"));
	return 0;
}
