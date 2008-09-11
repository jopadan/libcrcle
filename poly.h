#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

typedef uint8_t  poly8_t;
typedef uint16_t poly16_t;
typedef uint32_t poly32_t;
typedef uint64_t poly64_t;


/* poly8_t polynomial converter functions */
poly8_t reflect8( const poly8_t x );

poly8_t poly8_std_msb(poly8_t poly);
poly8_t poly8_rev_lsb(poly8_t poly);
poly8_t poly8_rev_recip(poly8_t poly);

poly8_t poly8_koopman_to_msb(poly8_t poly);
poly8_t poly8_koopman_to_lsb(poly8_t poly);
poly8_t poly8_lsb_to_koopman(poly8_t poly);
poly8_t poly8_msb_to_koopman(poly8_t poly);
poly8_t poly8_msb_to_lsb(poly8_t poly);
poly8_t poly8_lsb_to_msb(poly8_t poly);


/* poly16_t polynomial converter functions */
poly16_t poly16_reflect( const poly16_t x );

poly16_t poly16_std_msb(const poly16_t x);
poly16_t poly16_rev_lsb(const poly16_t x);
poly16_t poly16_rev_recip(const poly16_t x);

poly16_t poly16_koopman_to_msb(const poly16_t x);
poly16_t poly16_koopman_to_lsb(const poly16_t x);
poly16_t poly16_lsb_to_koopman(const poly16_t x);
poly16_t poly16_msb_to_koopman(const poly16_t x);
poly16_t poly16_msb_to_lsb(const poly16_t x);
poly16_t poly16_lsb_to_msb(const poly16_t x);


/* poly32_t polynomial converter functions */
poly32_t poly32_reflect( const poly32_t x );

poly32_t poly32_std_msb(const poly32_t x);
poly32_t poly32_rev_lsb(const poly32_t x);
poly32_t poly32_rev_recip(const poly32_t x);

poly32_t poly32_koopman_to_msb(const poly32_t x);
poly32_t poly32_koopman_to_lsb(const poly32_t x);
poly32_t poly32_lsb_to_koopman(const poly32_t x);
poly32_t poly32_msb_to_koopman(const poly32_t x);
poly32_t poly32_msb_to_lsb(const poly32_t x);
poly32_t poly32_lsb_to_msb(const poly32_t x);


/* poly64_t polynomial converter functions */
poly64_t poly64_reflect( const poly64_t x );

poly64_t poly64_std_msb(const poly64_t x);
poly64_t poly64_rev_lsb(const poly64_t x);
poly64_t poly64_rev_recip(const poly64_t x);

poly64_t poly64_koopman_to_msb(const poly64_t x);
poly64_t poly64_koopman_to_lsb(const poly64_t x);
poly64_t poly64_lsb_to_koopman(const poly64_t x);
poly64_t poly64_msb_to_koopman(const poly64_t x);
poly64_t poly64_msb_to_lsb(const poly64_t x);
poly64_t poly64_lsb_to_msb(const poly64_t x);



/* reflect poly8_t */
poly8_t poly8_reflect( const poly8_t x )
{
	poly8_t bits = 0;
	poly8_t mask = x;

	for( int i = 0; i < sizeof(x)*8; i++ )
	{
		bits <<= 1;
		if( mask & 1 )
			bits |= 1;
		mask >>= 1;
	}

	return bits;
}

/* normal MSB-first code                         */
/* 0x3 = 0b0011                                  */
/* x^4 + (0 * x^3 + 0 * x^2 + 1 * x^1 + 1 * x^0) */ 
poly8_t poly8_std_msb(poly8_t poly)
{
}
/* reversed LSB-first code                       */
/* 0xC = 0b1100                                  */
/* (1 * x^0 + 1 * x^1 + 0 * x^2 + 0 * x^3) + x^4 */
poly8_t poly8_rev_lsb(poly8_t poly)
{
}

/* reversed reciprocal Koopman notation          */
/* 0x9 = 0b1001                                  */
/* (1 * x^4 + 0 * x^3 + 0 * x^2 + 1 * x^1) + x^0 */
poly8_t poly8_rev_recip(poly8_t poly)
{
}
poly8_t poly8_koopman_to_msb(poly8_t poly)
{
	
}

poly8_t poly8_koopman_to_lsb(poly8_t poly)
{
}

poly8_t poly8_lsb_to_koopman(poly8_t poly)
{
}

poly8_t poly8_msb_to_koopman(poly8_t poly)
{
}

poly8_t poly8_msb_to_lsb(poly8_t poly)
{
}

poly8_t poly8_lsb_to_msb(poly8_t poly)
{
}


/* reflect poly16_t */
poly16_t poly16_reflect( const poly16_t x )
{
	poly16_t bits = 0;
	poly16_t mask = x;

	for( int i = 0; i < sizeof(x)*8; i++ )
	{
		bits <<= 1;
		if( mask & 1 )
			bits |= 1;
		mask >>= 1;
	}

	return bits;
}
/* normal MSB-first code                         */
/* 0x3 = 0b0011                                  */
/* x^4 + (0 * x^3 + 0 * x^2 + 1 * x^1 + 1 * x^0) */ 
poly16_t poly16_std_msb(poly16_t poly)
{
}

/* reversed LSB-first code                       */
/* 0xC = 0b1100                                  */
/* (1 * x^0 + 1 * x^1 + 0 * x^2 + 0 * x^3) + x^4 */
poly16_t poly16_rev_lsb(poly16_t poly)
{
}

/* reversed reciprocal Koopman notation          */
/* 0x9 = 0b1001                                  */
/* (1 * x^4 + 0 * x^3 + 0 * x^2 + 1 * x^1) + x^0 */
poly16_t poly16_rev_recip(poly16_t poly)
{
}

poly16_t poly16_koopman_to_msb(poly16_t poly)
{
	
}

poly16_t poly16_koopman_to_lsb(poly16_t poly)
{
}

poly16_t poly16_lsb_to_koopman(poly16_t poly)
{
}

poly16_t poly16_msb_to_koopman(poly16_t poly)
{
}

poly16_t poly16_msb_to_lsb(poly16_t poly)
{
}

poly16_t poly16_lsb_to_msb(poly16_t poly)
{
}


/* reflect poly32_t */
poly32_t poly32_reflect( const poly32_t x )
{
	poly32_t bits = 0;
	poly32_t mask = x;

	for( int i = 0; i < sizeof(x)*8; i++ )
	{
		bits <<= 1;
		if( mask & 1 )
			bits |= 1;
		mask >>= 1;
	}

	return bits;
}

/* normal MSB-first code                         */
/* 0x3 = 0b0011                                  */
/* x^4 + (0 * x^3 + 0 * x^2 + 1 * x^1 + 1 * x^0) */ 
poly32_t poly32_std_msb(poly32_t poly)
{
}

/* reversed LSB-first code                       */
/* 0xC = 0b1100                                  */
/* (1 * x^0 + 1 * x^1 + 0 * x^2 + 0 * x^3) + x^4 */
poly32_t poly32_rev_lsb(poly32_t poly)
{
}

/* reversed reciprocal Koopman notation          */
/* 0x9 = 0b1001                                  */
/* (1 * x^4 + 0 * x^3 + 0 * x^2 + 1 * x^1) + x^0 */
poly32_t poly32_rev_recip(poly32_t poly)
{
}

poly32_t poly32_koopman_to_msb(poly32_t poly)
{
	
}

poly32_t poly32_koopman_to_lsb(poly32_t poly)
{
}

poly32_t poly32_lsb_to_koopman(poly32_t poly)
{
}

poly32_t poly32_msb_to_koopman(poly32_t poly)
{
}

poly32_t poly32_msb_to_lsb(poly32_t poly)
{
}

poly32_t poly32_lsb_to_msb(poly32_t poly)
{
}


/* reflect poly64_t */
poly64_t poly64_reflect( const poly64_t x )
{
	poly64_t bits = 0;
	poly64_t mask = x;

	for( int i = 0; i < sizeof(x)*8; i++ )
	{
		bits <<= 1;
		if( mask & 1 )
			bits |= 1;
		mask >>= 1;
	}

	return bits;
}

/* normal MSB-first code                         */
/* 0x3 = 0b0011                                  */
/* x^4 + (0 * x^3 + 0 * x^2 + 1 * x^1 + 1 * x^0) */ 
poly64_t poly64_std_msb(poly64_t poly)
{
}

/* reversed LSB-first code                       */
/* 0xC = 0b1100                                  */
/* (1 * x^0 + 1 * x^1 + 0 * x^2 + 0 * x^3) + x^4 */
poly64_t poly64_rev_lsb(poly64_t poly)
{
}

/* reversed reciprocal Koopman notation          */
/* 0x9 = 0b1001                                  */
/* (1 * x^4 + 0 * x^3 + 0 * x^2 + 1 * x^1) + x^0 */
poly64_t poly64_rev_recip(poly64_t poly)
{
}


poly64_t poly64_koopman_to_msb(poly64_t poly)
{
}
poly64_t poly64_koopman_to_lsb(poly64_t poly)
{
}
poly64_t poly64_lsb_to_koopman(poly64_t poly)
{
}
poly64_t poly64_msb_to_koopman(poly64_t poly)
{
}
poly64_t poly64_msb_to_lsb(poly64_t poly)
{
}

poly64_t poly64_lsb_to_msb(poly64_t poly)
{
}
