#include <stdio.h>
int main (int argc, char**argv) {

	while ( !feof(stdin) ) {
		fprintf (stdout, "%d %d\n", fgetc(stdin)-128, fgetc(stdin)-128 );
	}
}

