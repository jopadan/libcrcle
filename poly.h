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

#define POLY32_CRC32_NORMAL                           0x04C11DB7 
#define POLY32_CRC32_REVERSED                         0xEDB88320
#define POLY32_CRC32_RECIPROCAL                       0xDB710641
#define POLY32_CRC32_REVERSED_RECIPROCAL              0x82608EDB

#define POLY32_CRC32C_CASTAGNOLIA_NORMAL              0x1EDC6F41
#define POLY32_CRC32C_CASTAGNOLIA_REVERSED            0x82F63B78
#define POLY32_CRC32C_CASTAGNOLIA_RECIPROCAL          0x05EC76F1
#define POLY32_CRC32C_CASTAGNOLIA_REVERSED_RECIPROCAL 0x8F6E37A0 



#define POLY32_CRC32K_KOOPMAN_1_3_28_NORMAL           0x741B8CD7
#define POLY32_CRC32K_KOOPMAN_1_3_28_REVERSED         0xEB31D82E
#define POLY32_CRC32K_KOOPMAN_1_3_28_RECIPROCAL       0xD663B05D
#define POLY32_CRC32K_KOOPMAN_1_3_28_REVERED_RECIPROCAL 0xBA0DC66B   
#define POLY32_CRC32K_KOOPMAN_1_1_30_NORMAL           0x32583499
#define POLY32_CRC32K_KOOPMAN_1_1_30_REVERSED         0x992C1A4C
#define POLY32_CRC32K_KOOPMAN_1_1_30_RECIPROCAL       0x32583499
#define POLY32_CRC32K_KOOPMAN_1_1_30_REVERED_RECIPROCAL 0x992C1A4C
#define POLY32_CRC32Q_NORMAL                          0x814141AB
#define POLY32_CRC32Q_REVERSED                        0xD5828281 
#define POLY32_CRC32Q_RECIPROCAL                      0xAB050503
#define POLY32_CRC32Q_REVERSED_RECIPROCAL             0xC0A0A0D5

/* poly8_t polynomial converter functions */
poly8_t reflect8( const poly8_t x );
poly8_t poly8_rotate_left(const poly8_t x, const unsigned int d);
poly8_t poly8_rotate_right(const poly8_t x, const unsigned int d);

poly8_t poly8_std_msb(poly8_t x);
poly8_t poly8_rev_lsb(poly8_t x);
poly8_t poly8_rev_rcp(poly8_t x);

#define poly8_rev_rcp_to_msb(x) poly8_rol(x,1)
#define poly8_rcp_to_msb(x) poly8_rol(x,1)
#define poly8_rev_rcp_to_lsb(x) poly8_reflect(poly8_rol(x,1))
#define poly8_rcp_to_lsb(x) poly8_ror(x,1)
#define poly8_rcp_to_rev_rcp(x) poly8_reflect(x)
#define poly8_rev_rcp_to_rcp(x) poly8_reflect(x)
#define poly8_lsb_to_rev_rcp(x) poly8_reflect(poly8_rol(x, 1))
#define poly8_msb_to_rev_rcp(x) poly8_ror(x, 1)
#define poly8_msb_to_lsb(x) poly8_reflect(x)
#define poly8_lsb_to_msb(x) poly8_reflect(x)

/* poly16_t polynomial converter functions */
poly16_t poly16_reflect( const poly16_t x );
poly16_t poly16_rol(const poly16_t x, const unsigned int d);
poly16_t poly16_ror(const poly16_t x, const unsigned int d);

poly16_t poly16_std_msb(const poly16_t x);
poly16_t poly16_rev_lsb(const poly16_t x);
poly16_t poly16_rev_rcp(const poly16_t x);

#define poly16_rev_rcp_to_msb(x) poly16_rol(x,1)
#define poly16_rcp_to_msb(x) poly16_rol(x,1)
#define poly16_rev_rcp_to_lsb(x) poly16_reflect(poly16_rol(x,1))
#define poly16_rcp_to_lsb(x) poly16_ror(x,1)
#define poly16_rcp_to_rev_rcp(x) poly16_reflect(x)
#define poly16_rev_rcp_to_rcp(x) poly16_reflect(x)
#define poly16_lsb_to_rev_rcp(x) poly16_reflect(poly16_rol(x, 1))
#define poly16_msb_to_rev_rcp(x) poly16_ror(x, 1)
#define poly16_msb_to_lsb(x) poly16_reflect(x)
#define poly16_lsb_to_msb(x) poly16_reflect(x)


/* poly32_t polynomial converter functions */
poly32_t poly32_reflect( const poly32_t x );
poly32_t poly32_rol(const poly32_t x, const unsigned int d);
poly32_t poly32_ror(const poly32_t x, const unsigned int d);

poly32_t poly32_std_msb(const poly32_t x);
poly32_t poly32_rev_lsb(const poly32_t x);
poly32_t poly32_rev_rcp(const poly32_t x);

#define poly32_rev_rcp_to_msb(x) poly32_rol(x,1)
#define poly32_rcp_to_msb(x) poly32_rol(x,1)
#define poly32_rev_rcp_to_lsb(x) poly32_reflect(poly32_rol(x,1))
#define poly32_rcp_to_lsb(x) poly32_ror(x,1)
#define poly32_rcp_to_rev_rcp(x) poly32_reflect(x)
#define poly32_rev_rcp_to_rcp(x) poly32_reflect(x)
#define poly32_lsb_to_rev_rcp(x) poly32_reflect(poly32_rol(x, 1))
#define poly32_msb_to_rev_rcp(x) poly32_ror(x, 1)
#define poly32_msb_to_lsb(x) poly32_reflect(x)
#define poly32_lsb_to_msb(x) poly32_reflect(x)
#define poly32_msb_to_rcp(x) poly32_reflect(poly32_ror(x, 1));

/* poly64_t polynomial converter functions */
poly64_t poly64_reflect( const poly64_t x );
poly64_t poly64_rol(const poly64_t x, const unsigned int d);
poly64_t poly64_ror(const poly64_t x, const unsigned int d);

poly64_t poly64_std_msb(const poly64_t x);
poly64_t poly64_rev_lsb(const poly64_t x);
poly64_t poly64_rev_rcp(const poly64_t x);


#define poly64_rev_rcp_to_msb(x) poly64_rol(x,1)
#define poly64_rcp_to_msb(x) poly64_rol(x,1)
#define poly64_rev_rcp_to_lsb(x) poly64_reflect(poly64_rol(x,1))
#define poly64_rcp_to_lsb(x) poly64_ror(x,1)
#define poly64_rcp_to_rev_rcp(x) poly64_reflect(x)
#define poly64_rev_rcp_to_rcp(x) poly64_reflect(x)
#define poly64_lsb_to_rev_rcp(x) poly64_reflect(poly32_rol(x, 1))
#define poly64_msb_to_rev_rcp(x) poly64_ror(x, 1)
#define poly64_msb_to_lsb(x) poly64_reflect(x)
#define poly64_lsb_to_msb(x) poly64_reflect(x)

