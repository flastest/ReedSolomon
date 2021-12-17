/* Example use of Reed-Solomon library
 *
 * Copyright Henry Minsky (hqm@alum.mit.edu) 1991-2009
 *
 * This software library is licensed under terms of the GNU GENERAL
 * PUBLIC LICENSE
 *
 * RSCODE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RSCODE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Rscode.  If not, see <http://www.gnu.org/licenses/>.

 * Commercial licensing is available under a separate license, please
 * contact author for details.
 *
 * This same code demonstrates the use of the encodier and
 * decoder/error-correction routines. 
 *
 * We are assuming we have at least four bytes of parity (NPAR >= 4).
 * 
 * This gives us the ability to correct up to two errors, or 
 * four erasures. 
 *
 * In general, with E errors, and K erasures, you will need
 * 2E + K bytes of parity to be able to correct the codeword
 * back to recover the original message data.
 *
 * You could say that each error 'consumes' two bytes of the parity,
 * whereas each erasure 'consumes' one byte.
 *
 * Thus, as demonstrated below, we can inject one error (location unknown)
 * and two erasures (with their locations specified) and the 
 * error-correction routine will be able to correct the codeword
 * back to the original message.
 * */
 
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include "ecc.h"
}
#include <cstring>
#include <random>

/* Some debugging routines to introduce errors or erasures
   into a codeword. 
   */

/* Introduce a byte error at LOC */
void
byte_err (int err, int loc, unsigned char *dst)
{
  printf("Adding Error at loc %d, data %#x\n", loc, dst[loc-1]);
  dst[loc] ^= err;
}


int
main (int argc, char *argv[])
{
  int erasures[16];
  int nerasures = 0;

  /* Initialization the ECC library */

  initialize_ecc ();

  unsigned char msg[] = "Nervously I loaded the twin ducks aboard the revolving platform.";
  int msg_len = strlen((const char *)msg);
  unsigned char codeword[256];

  printf("Running with NPAR %d\n", NPAR);
  /* ************** */

  /* Encode data into codeword, adding NPAR parity bytes */
  encode_data(msg, sizeof(msg), codeword);

  printf("Encoded data is: \"%s\"\n", codeword);

#define ML (sizeof (msg) + NPAR)



  int errors_to_insert = 1;
  if (argc > 1) {
    errors_to_insert = atoi(argv[1]);
  }
  std::random_device rd;
  for (int i = 0; i < errors_to_insert; i++) {
    int random_char = rd() % msg_len;
    int random_byte = rd() % 8;
    byte_err((1 << random_byte), random_char, codeword);
  }

  printf("with some errors: \"%s\"\n", codeword);


  /* Now decode -- encoded codeword size must be passed */
  decode_data(codeword, ML);

  /* check if syndrome is all zeros */
  if (check_syndrome () != 0) {
    correct_errors_erasures (codeword,
			     ML,
			     nerasures,
			     erasures);

    printf("Corrected codeword: \"%s\"\n", codeword);
  }

  int num_errors = 0;
  for (int i = 0; i < msg_len; i++) {
    if (codeword[i] != msg[i]) {
      num_errors++;
    }
  }
  printf("Errors after correction: %d\n", num_errors);

  return 0;
}

