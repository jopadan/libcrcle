#include "poly.h"

#define CRC32_TABLE_SIZE (UINT8_MAX + 1)

typedef enum crc_type_e
{
	CRC32_IEEE,
	CRC32_CCITT,
	CRC32_ZIP,
	CRC32A,
	CRC32B,
	CRC32C_CASTAGNOLIA,
	CRC32K_KOOPMAN_1_3_28,
	CRC32K_KOOPMAN_1_1_30,
	CRC32Q,
} crc_type_t;

typedef struct poly_s
{
	poly32_t std;
	poly32_t rev;
	poly32_t rcp;
	poly32_t rev_rcp;
	poly32_t ini;
} poly_t;
typedef struct bitcnt_s
{
		int8_t std;
		int8_t rev;
		int8_t rcp;
		int8_t rev_rcp;
		int8_t ini;
} bitcnt_t;

typedef struct primitive_s
{
	bool std;
	bool rev;
	bool rcp;
	bool rev_rcp;
	bool ini;
} primitive_t;

typedef struct parity_s
{
	bool std;
	bool rev;
	bool rcp;
	bool rev_rcp;
	bool ini;
} parity_t;

typedef struct table_s {
	poly32_t std[CRC32_TABLE_SIZE];
	poly32_t rev[CRC32_TABLE_SIZE];
	poly32_t rcp[CRC32_TABLE_SIZE];
	poly32_t rev_rcp[CRC32_TABLE_SIZE];
	poly32_t ini[CRC32_TABLE_SIZE];
} table_t;

typedef struct crc32_s
{
	crc_type_t type;
	poly_t poly;
	bitcnt_t bitcnt;
	parity_t parity;
	table_t table;

	bool rcp_int;
	bool rcp_out;
	bool ref_in;
	bool ref_out;
	bool xor_in;
	bool xor_out;
} crc32_t;

crc32_t* crc32_create(crc_type_t type, uint32_t ini);
crc32_t* crc32_delete(crc32_t* crc);
bool     crc32_recalc(crc32_t* crc);
uint32_t crc32_update(crc32_t* crc, uint8_t* data, size_t size);

