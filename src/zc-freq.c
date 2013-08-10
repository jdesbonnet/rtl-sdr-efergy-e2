#include <stdio.h>
#include <stdint.h>
int main (int argc, char**argv) {
	int v=0,pv=0,t=0;

	// negative to positive crossing time
	int ntpt=0;
	int f=0;

	while ( !feof(stdin) ) {
		t++;
		fscanf (stdin, "%d", &v);
		if (pv < 0 && v > 0) {
			ntpt = t;
		} else if (pv > 0 && v < 0) {
			f = t-ntpt;
		}
		pv = v;
		fprintf (stdout, "%d %d\n", t, f);
	}

}

