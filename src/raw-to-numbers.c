#include <stdio.h>
#include <stdint.h>
int main (int argc, char**argv) {
	int16_t v;
	while ( !feof(stdin) ) {
		v = fgetc(stdin) | fgetc(stdin)<<8;
		fprintf (stdout, "%d\n", v );
	}
}

