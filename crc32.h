#include "poly.h"

typedef enum crc_type_e
{
	CRC32-IEEE,
	CRC32-CCITT,
	CRC32-ZIP,
	CRC32A,
	CRC32B,
	CRC32C-CASTAGNOLIA,
	CRC32K-KOOPMAN_1_3_28,
	CRC32K-KOOPMAN_1_1_30,
	CRC32Q,
} crc_type_t;

typedef struct crc32_s
{
	crc_type_t type;

	struct poly {
		poly32_t std;
		poly32_t rev;
		poly32_t rcp;
		poly32_t rev_rcp;
		poly32_t ini;
	}

	struct bitcnt {
		int8_t std;
		int8_t rev;
		int8_t rcp;
		int8_t rev_rcp;
		int8_t ini;
	}

	struct parity {
		bool std;
		bool rev;
		bool rcp;
		bool rev_rcp;
		bool ini;
	}

	struct primitive {
		bool std;
		bool rev;
		bool rcp
		bool rev_rcp;
		bool ini;
	}

	struct table {
		poly32_t std[8][UINT8_MAX + 1];
		poly32_t rev[8][UINT8_MAX + 1];
		poly32_t rcp[8][UINT8_MAX + 1];
		poly32_t rev_rcp[8][UINT8_MAX + 1];
		poly32_t ini[8][UINT8_MAX + 1];
	}

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

