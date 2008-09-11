# libcrcle
CRC algorithm 32-bit variations C library

CRC checksum C library supporting 32-bit variants

based on source code from:

- [macutils](http://github.com/dgilman/macutils)
- [rhash](http://github.com/rhash/RHash)
- [crc32](http://github.com/MichaelAngel007/crc32)

# Status

```c
                               Normal     Reversed   Reciprocal Reversed reciprocal Parity Primitive
CRC32                        : 0x04C11DB7 0xEDB88320 0xDB710641 0x82608EDB            odd  yes
x^32 + x^26 +x^23 + x^22 + x^16 + x^12 + x^11 + x^10 + x^8 + x^7 + x^5 + x^4 + x^2 + x + 1
CRC-32C (Castanoglia)        : 0x1EDC6F41 0x82F63B78 0x05EC76F1 0x8F6E37A0            even yes
x^32 + x^28 + x^27 + x^26 + x^25 + x^23 + x^22 + x^20 + x^19 + x^18 + x^14 + x^13 + x^11 + x^10 + x^9 + x^8 + x^6 + 1
CRC-32K (Koopman {1,2,28})   : 0x741B8CD7 0xEB31D82E 0xD663B05D 0xBA0DC66B            even no
x^32 + x^30 + x^29 + x^28 + x^26 + x^20 + x^19 + x^17 + x^16 + x^15 + x^11 + x^10 + x^7 + x^6 + x^4 + x^2 + x + 1
CRC-32K (Koopman {1,1,30})   : 0x32583499 0x992C1A4C 0x32583499 0x992C1A4C            even no
CRC-32Q                      : 0x814141AB 0xD5828281 0xAB050503 0xC0A0A0D5            even yes
x^32 + x^31 + x^24 + x^22 + x^16 + x^14 + x^8 + x^7 + x^5 + x^3 + x + 1
CRC-CCITT32                  : 0x04c11db7 - 0xffffffff
ZIP     		     : ZIP         - 0xedb88320 - 0xffffffff
```

# Build

```c
cmake .
make install
```

# Usage

```c
crcchk [OPTION]... [FILE]...
Output CRC checksum file of listed files in option defined style.

      --crc32           use CRC32 algorithm
      --crc32c          use CRC32C algorithm
      --ccitt32         use CCITT32 algorithm
      --zip             use ZIP style of algorithm
  -t, --table      	print CRC table.
      --poly=POLYGON	use POLYGON to generate table.
      --start=START	use START as starting value for CRC.
      --simple      	print message digests, using simple format (default).
      --sfv         	print message digests, using SFV format.
      --bsd         	print message digests, using BSD-like format.
```
