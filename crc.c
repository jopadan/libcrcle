#include "crc.h"

crc_type_t crc_type = CRC_CRC32;
chksum_style_t chksum_style = CHKSUM_STYLE_SIMPLE;

uint32_t crc32_crcinit = -1;
uint32_t crc32c_crcinit = -1;
uint32_t ccitt32_crcinit = -1;
uint32_t zip_crcinit = -1;

char* chksum_style_str[CHKSUM_STYLE_SIZE] =
{
	"simple",
	"sfv",
	"bsd",
};

char* chksum_type_str[CRC_TYPE_SIZE] = 
{
	"crc32",
	"crc32c",
	"ccitt32",
	"zip",
};

uint32_t crc32(crc_type_t crc_type, uint32_t start, uint8_t* bytes, size_t size)
{
	uint32_t crc = 0;
	switch(crc_type)
	{
		case CRC_CRC32:
			crc = crc32_updcrc(start, bytes, size);
			break;
		case CRC_CRC32C:
			crc = crc32c_updcrc(start, bytes, size);
			break;
		case CRC_CCITT32:
			crc = ccitt32_updcrc(start, bytes, size);
			break;
		case CRC_ZIP:
			crc = zip_updcrc(start, bytes, size);
			break;
		default:
			crc = 0;
			break;

	}
	return crc;
}




uint32_t crctab[CRC_TYPE_SIZE][256] =
{
	[CRC_CRC32] = 
	{
		0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
		0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
		0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
		0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
		0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
		0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
		0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
		0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
		0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
		0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
		0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
		0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
		0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
		0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
		0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
		0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
		0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
		0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
		0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
		0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
		0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
		0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
		0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
		0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
		0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
		0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
		0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
		0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
		0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
		0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
		0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
		0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
		0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
		0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
		0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
		0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
		0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
		0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
		0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
		0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
		0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
		0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
		0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
		0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
		0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
		0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
		0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
		0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
		0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
		0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
		0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
		0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
		0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
		0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
		0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
		0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
		0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
		0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
		0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
		0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
		0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
		0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
		0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
		0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
	},
	[CRC_CRC32C] =
	{ 
		0x00000000, 0xf26b8303, 0xe13b70f7, 0x1350f3f4,
		0xc79a971f, 0x35f1141c, 0x26a1e7e8, 0xd4ca64eb,
		0x8ad958cf, 0x78b2dbcc, 0x6be22838, 0x9989ab3b,
		0x4d43cfd0, 0xbf284cd3, 0xac78bf27, 0x5e133c24,
		0x105ec76f, 0xe235446c, 0xf165b798, 0x030e349b,
		0xd7c45070, 0x25afd373, 0x36ff2087, 0xc494a384,
		0x9a879fa0, 0x68ec1ca3, 0x7bbcef57, 0x89d76c54,
		0x5d1d08bf, 0xaf768bbc, 0xbc267848, 0x4e4dfb4b,
		0x20bd8ede, 0xd2d60ddd, 0xc186fe29, 0x33ed7d2a,
		0xe72719c1, 0x154c9ac2, 0x061c6936, 0xf477ea35,
		0xaa64d611, 0x580f5512, 0x4b5fa6e6, 0xb93425e5,
		0x6dfe410e, 0x9f95c20d, 0x8cc531f9, 0x7eaeb2fa,
		0x30e349b1, 0xc288cab2, 0xd1d83946, 0x23b3ba45,
		0xf779deae, 0x05125dad, 0x1642ae59, 0xe4292d5a,
		0xba3a117e, 0x4851927d, 0x5b016189, 0xa96ae28a,
		0x7da08661, 0x8fcb0562, 0x9c9bf696, 0x6ef07595,
		0x417b1dbc, 0xb3109ebf, 0xa0406d4b, 0x522bee48,
		0x86e18aa3, 0x748a09a0, 0x67dafa54, 0x95b17957,
		0xcba24573, 0x39c9c670, 0x2a993584, 0xd8f2b687,
		0x0c38d26c, 0xfe53516f, 0xed03a29b, 0x1f682198,
		0x5125dad3, 0xa34e59d0, 0xb01eaa24, 0x42752927,
		0x96bf4dcc, 0x64d4cecf, 0x77843d3b, 0x85efbe38,
		0xdbfc821c, 0x2997011f, 0x3ac7f2eb, 0xc8ac71e8,
		0x1c661503, 0xee0d9600, 0xfd5d65f4, 0x0f36e6f7,
		0x61c69362, 0x93ad1061, 0x80fde395, 0x72966096,
		0xa65c047d, 0x5437877e, 0x4767748a, 0xb50cf789,
		0xeb1fcbad, 0x197448ae, 0x0a24bb5a, 0xf84f3859,
		0x2c855cb2, 0xdeeedfb1, 0xcdbe2c45, 0x3fd5af46,
		0x7198540d, 0x83f3d70e, 0x90a324fa, 0x62c8a7f9,
		0xb602c312, 0x44694011, 0x5739b3e5, 0xa55230e6,
		0xfb410cc2, 0x092a8fc1, 0x1a7a7c35, 0xe811ff36,
		0x3cdb9bdd, 0xceb018de, 0xdde0eb2a, 0x2f8b6829,
		0x82f63b78, 0x709db87b, 0x63cd4b8f, 0x91a6c88c,
		0x456cac67, 0xb7072f64, 0xa457dc90, 0x563c5f93,
		0x082f63b7, 0xfa44e0b4, 0xe9141340, 0x1b7f9043,
		0xcfb5f4a8, 0x3dde77ab, 0x2e8e845f, 0xdce5075c,
		0x92a8fc17, 0x60c37f14, 0x73938ce0, 0x81f80fe3,
		0x55326b08, 0xa759e80b, 0xb4091bff, 0x466298fc,
		0x1871a4d8, 0xea1a27db, 0xf94ad42f, 0x0b21572c,
		0xdfeb33c7, 0x2d80b0c4, 0x3ed04330, 0xccbbc033,
		0xa24bb5a6, 0x502036a5, 0x4370c551, 0xb11b4652,
		0x65d122b9, 0x97baa1ba, 0x84ea524e, 0x7681d14d,
		0x2892ed69, 0xdaf96e6a, 0xc9a99d9e, 0x3bc21e9d,
		0xef087a76, 0x1d63f975, 0x0e330a81, 0xfc588982,
		0xb21572c9, 0x407ef1ca, 0x532e023e, 0xa145813d,
		0x758fe5d6, 0x87e466d5, 0x94b49521, 0x66df1622,
		0x38cc2a06, 0xcaa7a905, 0xd9f75af1, 0x2b9cd9f2,
		0xff56bd19, 0x0d3d3e1a, 0x1e6dcdee, 0xec064eed,
		0xc38d26c4, 0x31e6a5c7, 0x22b65633, 0xd0ddd530,
		0x0417b1db, 0xf67c32d8, 0xe52cc12c, 0x1747422f,
		0x49547e0b, 0xbb3ffd08, 0xa86f0efc, 0x5a048dff,
		0x8ecee914, 0x7ca56a17, 0x6ff599e3, 0x9d9e1ae0,
		0xd3d3e1ab, 0x21b862a8, 0x32e8915c, 0xc083125f,
		0x144976b4, 0xe622f5b7, 0xf5720643, 0x07198540,
		0x590ab964, 0xab613a67, 0xb831c993, 0x4a5a4a90,
		0x9e902e7b, 0x6cfbad78, 0x7fab5e8c, 0x8dc0dd8f,
		0xe330a81a, 0x115b2b19, 0x020bd8ed, 0xf0605bee,
		0x24aa3f05, 0xd6c1bc06, 0xc5914ff2, 0x37faccf1,
		0x69e9f0d5, 0x9b8273d6, 0x88d28022, 0x7ab90321,
		0xae7367ca, 0x5c18e4c9, 0x4f48173d, 0xbd23943e,
		0xf36e6f75, 0x0105ec76, 0x12551f82, 0xe03e9c81,
		0x34f4f86a, 0xc69f7b69, 0xd5cf889d, 0x27a40b9e,
		0x79b737ba, 0x8bdcb4b9, 0x988c474d, 0x6ae7c44e,
		0xbe2da0a5, 0x4c4623a6, 0x5f16d052, 0xad7d5351
	},
	[CRC_CCITT32] =
	{ 
		0x00000000, 0x04c11db7, 0x09823b6e, 0x0d4326d9,
		0x130476dc, 0x17c56b6b, 0x1a864db2, 0x1e475005,
		0x2608edb8, 0x22c9f00f, 0x2f8ad6d6, 0x2b4bcb61,
		0x350c9b64, 0x31cd86d3, 0x3c8ea00a, 0x384fbdbd,
		0x4c11db70, 0x48d0c6c7, 0x4593e01e, 0x4152fda9,
		0x5f15adac, 0x5bd4b01b, 0x569796c2, 0x52568b75,
		0x6a1936c8, 0x6ed82b7f, 0x639b0da6, 0x675a1011,
		0x791d4014, 0x7ddc5da3, 0x709f7b7a, 0x745e66cd,
		0x9823b6e0, 0x9ce2ab57, 0x91a18d8e, 0x95609039,
		0x8b27c03c, 0x8fe6dd8b, 0x82a5fb52, 0x8664e6e5,
		0xbe2b5b58, 0xbaea46ef, 0xb7a96036, 0xb3687d81,
		0xad2f2d84, 0xa9ee3033, 0xa4ad16ea, 0xa06c0b5d,
		0xd4326d90, 0xd0f37027, 0xddb056fe, 0xd9714b49,
		0xc7361b4c, 0xc3f706fb, 0xceb42022, 0xca753d95,
		0xf23a8028, 0xf6fb9d9f, 0xfbb8bb46, 0xff79a6f1,
		0xe13ef6f4, 0xe5ffeb43, 0xe8bccd9a, 0xec7dd02d,
		0x34867077, 0x30476dc0, 0x3d044b19, 0x39c556ae,
		0x278206ab, 0x23431b1c, 0x2e003dc5, 0x2ac12072,
		0x128e9dcf, 0x164f8078, 0x1b0ca6a1, 0x1fcdbb16,
		0x018aeb13, 0x054bf6a4, 0x0808d07d, 0x0cc9cdca,
		0x7897ab07, 0x7c56b6b0, 0x71159069, 0x75d48dde,
		0x6b93dddb, 0x6f52c06c, 0x6211e6b5, 0x66d0fb02,
		0x5e9f46bf, 0x5a5e5b08, 0x571d7dd1, 0x53dc6066,
		0x4d9b3063, 0x495a2dd4, 0x44190b0d, 0x40d816ba,
		0xaca5c697, 0xa864db20, 0xa527fdf9, 0xa1e6e04e,
		0xbfa1b04b, 0xbb60adfc, 0xb6238b25, 0xb2e29692,
		0x8aad2b2f, 0x8e6c3698, 0x832f1041, 0x87ee0df6,
		0x99a95df3, 0x9d684044, 0x902b669d, 0x94ea7b2a,
		0xe0b41de7, 0xe4750050, 0xe9362689, 0xedf73b3e,
		0xf3b06b3b, 0xf771768c, 0xfa325055, 0xfef34de2,
		0xc6bcf05f, 0xc27dede8, 0xcf3ecb31, 0xcbffd686,
		0xd5b88683, 0xd1799b34, 0xdc3abded, 0xd8fba05a,
		0x690ce0ee, 0x6dcdfd59, 0x608edb80, 0x644fc637,
		0x7a089632, 0x7ec98b85, 0x738aad5c, 0x774bb0eb,
		0x4f040d56, 0x4bc510e1, 0x46863638, 0x42472b8f,
		0x5c007b8a, 0x58c1663d, 0x558240e4, 0x51435d53,
		0x251d3b9e, 0x21dc2629, 0x2c9f00f0, 0x285e1d47,
		0x36194d42, 0x32d850f5, 0x3f9b762c, 0x3b5a6b9b,
		0x0315d626, 0x07d4cb91, 0x0a97ed48, 0x0e56f0ff,
		0x1011a0fa, 0x14d0bd4d, 0x19939b94, 0x1d528623,
		0xf12f560e, 0xf5ee4bb9, 0xf8ad6d60, 0xfc6c70d7,
		0xe22b20d2, 0xe6ea3d65, 0xeba91bbc, 0xef68060b,
		0xd727bbb6, 0xd3e6a601, 0xdea580d8, 0xda649d6f,
		0xc423cd6a, 0xc0e2d0dd, 0xcda1f604, 0xc960ebb3,
		0xbd3e8d7e, 0xb9ff90c9, 0xb4bcb610, 0xb07daba7,
		0xae3afba2, 0xaafbe615, 0xa7b8c0cc, 0xa379dd7b,
		0x9b3660c6, 0x9ff77d71, 0x92b45ba8, 0x9675461f,
		0x8832161a, 0x8cf30bad, 0x81b02d74, 0x857130c3,
		0x5d8a9099, 0x594b8d2e, 0x5408abf7, 0x50c9b640,
		0x4e8ee645, 0x4a4ffbf2, 0x470cdd2b, 0x43cdc09c,
		0x7b827d21, 0x7f436096, 0x7200464f, 0x76c15bf8,
		0x68860bfd, 0x6c47164a, 0x61043093, 0x65c52d24,
		0x119b4be9, 0x155a565e, 0x18197087, 0x1cd86d30,
		0x029f3d35, 0x065e2082, 0x0b1d065b, 0x0fdc1bec,
		0x3793a651, 0x3352bbe6, 0x3e119d3f, 0x3ad08088,
		0x2497d08d, 0x2056cd3a, 0x2d15ebe3, 0x29d4f654,
		0xc5a92679, 0xc1683bce, 0xcc2b1d17, 0xc8ea00a0,
		0xd6ad50a5, 0xd26c4d12, 0xdf2f6bcb, 0xdbee767c,
		0xe3a1cbc1, 0xe760d676, 0xea23f0af, 0xeee2ed18,
		0xf0a5bd1d, 0xf464a0aa, 0xf9278673, 0xfde69bc4,
		0x89b8fd09, 0x8d79e0be, 0x803ac667, 0x84fbdbd0,
		0x9abc8bd5, 0x9e7d9662, 0x933eb0bb, 0x97ffad0c,
		0xafb010b1, 0xab710d06, 0xa6322bdf, 0xa2f33668,
		0xbcb4666d, 0xb8757bda, 0xb5365d03, 0xb1f740b4,
	},

	[CRC_ZIP] = {
		0x00000000, 0x77073096, 0xee0e612c, 0x990951ba,
		0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3,
		0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
		0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91,
		0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de,
		0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
		0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec,
		0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5,
		0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
		0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b,
		0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940,
		0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
		0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116,
		0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f,
		0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
		0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d,
		0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a,
		0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
		0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818,
		0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01,
		0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
		0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457,
		0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c,
		0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
		0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2,
		0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb,
		0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
		0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9,
		0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086,
		0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
		0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4,
		0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad,
		0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
		0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683,
		0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8,
		0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
		0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe,
		0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7,
		0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
		0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5,
		0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252,
		0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
		0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60,
		0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79,
		0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
		0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f,
		0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04,
		0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
		0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a,
		0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713,
		0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
		0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21,
		0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e,
		0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
		0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c,
		0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45,
		0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
		0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db,
		0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0,
		0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
		0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6,
		0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf,
		0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
		0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d,
	},
};

bool crc32_inittab(uint32_t poly)
{
	register uint32_t crc = poly;
	for (uint8_t i = 0; i < CRC_TABLE_32; ++i)
	{
		crc = i;
		for (uint8_t j = 8; j > 0; --j)
		{
			if ((crc & 1) == 1)
			{
				crc = (uint32_t)((crc >> 1) ^ poly);
			}
			else
			{
				crc >>= 1;
			}
		}
		crctab[CRC_CRC32][i] = crc;
	}
}

uint32_t crc32_updcrc(uint32_t icrc, uint8_t* icp, size_t icnt)
{
	register uint32_t crc = icrc;
	register uint8_t* cp = icp;
	register size_t cnt = icnt;

	while(cnt--)
	{
		crc=((crc>>8)^crctab[CRC_CRC32][(crc&0xff)^*cp++]);
	}
	return ~crc;

}

uint32_t crc32c_updcrc(uint32_t icrc, uint8_t* icp, size_t icnt)
{
	register uint32_t crc = icrc;
	register uint8_t* cp = icp;
	register size_t cnt = icnt;

	while(cnt--)
	{
		crc=((crc>>8)^crctab[CRC_CRC32C][(crc&0xff)^*cp++]);
	}
	return ~crc;

}

uint32_t ccitt32_updcrc(uint32_t icrc, uint8_t* icp, size_t icnt)
{
#define M1 0xffffff
#define M2 0xffffff00
    register uint32_t crc = icrc;
    register uint8_t *cp = icp;
    register size_t cnt = icnt;

    while(cnt--) {
	crc=((crc<<8)&M2)^crctab[CRC_CCITT32][((crc>>24)&0xff)^*cp++];
    }

    return(crc);
}

uint32_t zip_updcrc(uint32_t icrc, uint8_t* icp, size_t icnt)
{
#define M1 0xffffff
#define M2 0xffffff00
    register uint32_t crc = icrc;
    register uint8_t *cp = icp;
    register size_t cnt = icnt;

    while(cnt--) {
	crc=((crc>>8)&M1)^crctab[CRC_ZIP][(crc&0xff)^*cp++];
    }

    return(crc);
}

