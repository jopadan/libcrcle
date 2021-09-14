#include "poly.h"

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
poly8_t poly8_std_msb(const poly8_t x)
{
}
/* reversed LSB-first code                       */
/* 0xC = 0b1100                                  */
/* (1 * x^0 + 1 * x^1 + 0 * x^2 + 0 * x^3) + x^4 */
poly8_t poly8_rev_lsb(const poly8_t x)
{
}

/* reversed reciprocal Koopman notation          */
/* 0x9 = 0b1001                                  */
/* (1 * x^4 + 0 * x^3 + 0 * x^2 + 1 * x^1) + x^0 */
poly8_t poly8_rev_recip(const poly8_t x)
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

poly32_t poly32_rol(const poly32_t x, const unsigned int d)
{
	return ( x << d) | (x >> (sizeof(x) * 8 - d));
}

poly32_t poly32_ror(const poly32_t x, const unsigned int d)
{
	return ( x >> d) | (x << (sizeof(x) * 8 - d));
}

/* normal MSB-first code                         */
/* 0x09 = 0b0000 1001                                  */
/* x^4 + (0 * x^3 + 0 * x^2 + 1 * x^1 + 1 * x^0) */ 
poly32_t poly32_std_msb(poly32_t poly)
{
}

/* reversed LSB-first code                       */
/* 0x12 = 0b0001 0010                            */
/* (1 * x^0 + 1 * x^1 + 0 * x^2 + 0 * x^3) + x^4 */
poly32_t poly32_rev_lsb(poly32_t poly)
{
}
/* reciprocal Koopman notation                   */
/* 0x05 = 0b0000 0101                            */
/* (1 * x^5 + 0 * x^4 + 1 * x^3 + 0 * x^2 + 1 * x^1) + x^0 */
poly32_t poly32_recip(poly32_t poly)
{
}

/* reversed reciprocal Koopman notation          */
/* 0x14 = 0b0001 0100                            */
/* x^0 + (0 * x^1 + 0 * x^2 + 1 * x^3 + 0 * x^4 + 1 * x^5)  */
poly32_t poly32_rev_recip(poly32_t poly)
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

