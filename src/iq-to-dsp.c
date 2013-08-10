#include <stdio.h>
int main (int argc, char**argv) {

	while ( !feof(stdin) ) {
		fprintf (stdout, "%d\n", fgetc(stdin) );
		fgetc(stdin);
	}
}

