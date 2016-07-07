#ifndef _ISO_FS_I
#define _ISO_FS_I

#include <linux/fs.h>

enum isofs_file_format {
	isofs_file_normal = 0,
	isofs_file_sparse = 1,
	isofs_file_compressed = 2,
};
	

#endif
