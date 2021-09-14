#include "poly.h"
#include "crc32.h"

#define POLY32_CRC_STD 0x04C11DB7
#define POLY32_CRC_REVERSED 0xEDB88320 
#define POLY32_CRC_RECIPROCAL 0xDB710641
#define POLY32_CRC_REVERSED_RECIPROCAL 0x82608EDB


int main(int argc, char** argv)
{
	int exit_status = EXIT_FAILURE;
	crc32_t crc = crc32_create(CRC32-IEEE, 0xFFFFFFFF );
	uint32_t val = crc32_update(crc, 
	exit(exit_status);
}
