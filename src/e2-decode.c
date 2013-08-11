#include <stdio.h>
int main (int argc, char**argv) {
	int i=0;
	int v=0;
	int t=0;
	int bit_count = 0;
	int shift_reg = 0;
	int symbol = 0;
	int lc=0;

while(!feof(stdin)) {

	// Look for frame leader
	lc = 0;
	while ( !feof(stdin) ) {
		fscanf (stdin, "%d %d", &t, &v);

		if (v>=6 && v <=8) {
			lc++;
		} else {
			if (lc > 3000) {
				break;
			} else {
				lc = 0;
			}
		}

		i++;
		if (i % 10000 == 0) {
			fprintf (stdout,"*");
			fflush (stdout);
		}
	}

	fprintf (stdout,"\nSTART OF FRAME: lc=%d ",lc);
	bit_count = 0;
	shift_reg = 0;


	while ( !feof(stdin) ) {
		fscanf (stdin, "%d %d", &t, &v);
		//fprintf (stdout, "v=%d ",v);
		if ( v>=13 && v <= 17) {
			symbol=1;
		} else if ( v >= 9 && v <= 12) {
			symbol=0;
		} else {
			symbol=-1;
		}

		if (symbol != -1) {
			shift_reg <<= 1;
 			shift_reg |= symbol;
			bit_count++;
			if (bit_count % 8 == 0) {
				fprintf (stdout,"%x ",shift_reg & 0xff);
				if (bit_count > 1000*8) {
					fprintf (stdout," END OF FRAME.\n");
					break;
				}
			}
		} else {
			fprintf (stdout,"*%d* ",v);
		} 
		
	}

	}

}

