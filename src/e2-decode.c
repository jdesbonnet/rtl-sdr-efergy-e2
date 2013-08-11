#include <stdio.h>
int main (int argc, char**argv) {
	int i=0;
	int v=0;
	int t=0;
	int bit_count = 0;
	int shift_reg = 0;
	int symbol = 0;
	int lc=0;

	int freq=0;
	int prevfreq=0;
	int nbit=0;

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

	fprintf (stdout,"\nSTART OF FRAME: lc=%d t=%d",lc,t);
	bit_count = 0;
	shift_reg = 0;
	lc=0;
	

	while ( !feof(stdin) ) {

		fscanf (stdin, "%d %d", &t, &v);
		
		if ( v>=13 && v <= 17) {
			freq=1;
		} else if ( v >= 9 && v <= 12) {
			freq=0;
		} else {
			//freq=-1;
			//fprintf (stdout, "bit_count=%d v=%d t=%d\n", bit_count,v,t);
			//break;
			// ignore
		}

		if (freq == prevfreq) {
			lc++;
		} else {
			nbit = (lc+45)/90;
			//fprintf (stdout, "%d (%d %d)\n", prevfreq, lc, nbit);
			fflush (stdout);
			while (nbit !=0) {
				shift_reg <<= 1;
				shift_reg |= prevfreq;
				bit_count++;
				if (bit_count%8==0) {
					fprintf (stdout,"[%x] ",shift_reg & 0xff);
				}
				nbit--;
			}
			lc=0;
			prevfreq=freq;

			if (bit_count > 8*16) {
				break;
			}
		}

		
			
	}

	}

}

