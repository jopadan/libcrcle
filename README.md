# libcrcle
CRC algorithm 32-bit variations C library

CRC checksum C library supporting 32-bit variants used
in Bullfrog and Terminal Reality assets.

based on source code from:

- [macutils](http://github.com/dgilman/macutils)
- [rhash](http://github.com/rhash/RHash)
- [crc32](http://github.com/MichaelAngel007/crc32)

# Status
```c
CRC32                   : CRC32       - 0xedb88320 - 0xffffffff
CRC32C                  : CRC32C      -
CRC-CCITT32             : CRC-CCITT32 - 0x04c11db7 - 0xffffffff
ZIP     		      : ZIP         - 0xedb88320 - 0xffffffff
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
