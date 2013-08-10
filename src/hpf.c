#include <stdio.h>
#include <stdint.h>
int main (int argc, char**argv) {
	int v,t=0;
	while ( !feof(stdin) ) {
		fscanf (stdin, "%d", &v);
		t += v/16;
		t -= t/16;
		fprintf (stdout, "%d\n", v-t);
	}
}

