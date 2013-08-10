#include <stdio.h>
int main (int argc, char**argv) {
	int v=0, pv=0;
	int t=0, pt=0;
	int last_symbol_t = 0;
	int frame_mode = 0;
	int bit_count = 0;
	int shift_reg = 0;
	int byte_count = 0;

	while ( !feof(stdin) ) {
		fscanf (stdin, "%d %d", &t, &v);

		if (t - pt > 3000) {
			fprintf (stdout,"\nSTART OF FRAME:\n");
			frame_mode=1;
			bit_count = 0;
			shift_reg = 0;
			byte_count = 0;
		}

		if ( frame_mode && v>=13 && v <= 17) {
			if ( (t - last_symbol_t) > 1000) {
				fprintf (stdout,"\n");
			}
			//fprintf(stdout,"1");
			shift_reg <<= 1;
 			shift_reg |= 0x01;
			bit_count++;
			if (bit_count == 8) {
				fprintf (stdout,"[%x]",shift_reg);
				bit_count=0;
				shift_reg=0;
				byte_count++;
			}
			last_symbol_t = t;
		} else if (frame_mode && v >= 8 && v <= 12) {
			if ( (t - last_symbol_t) > 1000) {
				fprintf (stdout,"\n");
			}
			//fprintf(stdout,"0");
			shift_reg <<= 1;
			bit_count++;
			if (bit_count == 8) {
				fprintf (stdout,"[%x]",shift_reg);
				bit_count=0;
				shift_reg=0;
				byte_count++;
			}
			last_symbol_t = t;
		} else {
			if (frame_mode) {
				fprintf (stdout,"***\n***\n");
			}
			frame_mode = 0;
		}

		pv = v;
		pt = t;
	}

}

