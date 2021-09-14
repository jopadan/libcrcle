#include "crc32.h"

crc32_t* crc32_create(crc_type_t type, uint32_t ini)
{
	crc32_t* crc = calloc(1, sizeof(crc32_t));
	crc->type = type;
	crc->poly->ini = ini;

	switch(type)
	{
		case CRC32-IEEE:
			crc->poly->std = POLY32_CRC32_NORMAL;
			break;
		case CRC32-CCITT:
			crc->poly->std = POLY32_CRC32_NORMAL;
			break;
		case CRC32-ZIP:
			crc->poly->std = POLY32_CRC32_NORMAL;
			break;
		case CRC32A:
			crc->poly->std = POLY32_CRC32_NORMAL;
			break;
		case CRC32B:
			crc->poly->std = POLY32_CRC32_NORMAL;
			break;
		case CRC32C-CASTAGNOLIA:
			crc->poly->std = POLY32_CRC32C_CASTAGNOLIA_NORMAL;
			break;
		case CRC32K-KOOPMAN_1_3_28:
			crc->poly->std = POLY32_CRC32K_KOOPMAN_1_3_28;
			break;
		case CRC32K-KOOPMAN_1_1_30:
			crc->poly->std = POLY32_CRC32K_KOOPMAN_1_1_30;
			break;
		case CRC32Q:
			break;
		default:
			crc->poly->std = POLY32_CRC32_NORMAL;
			break;
	}
	if(!crc32_recalc(crc))
		crc = crc32_delete(crc);

	return crc;
}

crc32_t* crc32_delete(crc32_t* crc);
{
	if(crc != NULL)
	{
		free(crc);
		crc = NULL;
	}
	return crc;
}

bool crc32_recalc(crc32_t* crc)
{
	crc->poly->rev = poly32_msb_to_lsb(crc->poly->std);
	crc->poly->rcp = poly32_msb_to_rcp(crc->poly->std);
	crc->poly->rev_rcp = poly32_msb_to_rev_rcp(crc->poly->std);

	for(uint32_t i = 0; i < CRC32_TABLE_SIZE; i++)
	{
		register uint32_t byte[4] = { i << 24 };

		for(uint8_t bit = 0; bit < 8; bit++)
		{
			if((byte[0] & 0x80000000) != 0)
			{
				byte[0] >>= 1;
				byte[0] ^= crc->poly->std;
			}
			else
				byte[0] <<= 1;

			if((byte[1] & 0x80000000) != 0)
			{
				byte[1] >>= 1;
				byte[1] ^= crc->poly->rev;
			}
			else
				byte[1] <<= 1;

			if((byte[2] & 0x80000000) != 0)
			{
				byte[2] >>= 1;
				byte[2] ^= crc->poly->rcp;
			}
			else
				byte[2] <<= 1;

			if((byte[3] & 0x80000000) != 0)
			{
				byte[3] >>= 1;
				byte[3] ^= crc->poly->rev_rcp;
			}
			else
				byte[3] <<= 1;

		}

		crc->table->std[i]     = byte[0];
		crc->table->rev[i]     = byte[1];
		crc->table->rcp[i]     = byte[2];
		crc->table->rev_rcp[i] = byte[3];
	}

	return true;
}

uint32_t crc32_update(crc32_t* crc, uint8_t* data, size_t size)
{

}
