#include "poly.h"
#include "crc32.h"

#define POLY32_CRC_STD 0x04C11DB7
#define POLY32_CRC_REVERSED 0xEDB88320 
#define POLY32_CRC_RECIPROCAL 0xDB710641
#define POLY32_CRC_REVERSED_RECIPROCAL 0x82608EDB


int main(int argc, char** argv)
{
	int exit_status = EXIT_FAILURE;
	crc32_t* crc = crc32_create(CRC32_IEEE, 0xFFFFFFFF);
	struct stat sb;
	stat(argv[1], &sb);
	if(!sb.st_size)
		exit(exit_status);
	FILE* file = fopen(argv[1], "rb");
	uint8_t* data = calloc(1, sb.st_size);
	if(fread(data, 1, sb.st_size, file) != sb.st_size )
	{
		fprintf(stderr, "Error reading: %lu %s\n", sb.st_size, argv[1]);
		free(data);
		fclose(file);
		exit(exit_status);
	}

	fclose(file);

	uint32_t val = crc32_update(crc, data, sb.st_size);
	printf("%08x\n", val);
	free(data);
	exit_status=EXIT_SUCCESS;
	exit(exit_status);
}
