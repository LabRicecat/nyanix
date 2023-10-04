#ifndef NYANIX_NXDF_HPP
#define NYANIX_NXDF_HPP

#include <stdint.h>

/*
MAGIC MAGIC MAGIC MAGIC 
SIZE SIZE SIZE SIZE 
SIZE SIZE SIZE SIZE

BLOCK BLOCK BLOCK BLOCK 
<4000x64>

BLOCK BLOCK BLOCK BLOCK
<4000x64>
*/

#define NYANIX_NXDF_MAGIC_START 0
#define NYANIX_NXDF_SIZE_START (NYANIX_NXDF_MAGIC_START + 4)
#define NYANIX_NXDF_DISKSTART (NYANIX_NXDF_SIZE_START + sizeof(nxdfs_t))

#define NYANIX_NXDF_MAGIC0 41
#define NYANIX_NXDF_MAGIC1 15
#define NYANIX_NXDF_MAGIC2 1 
#define NYANIX_NXDF_MAGIC3 102

using nxdfs_t = uint32_t;
struct nxdf {
    char* file = 0;
    nxdfs_t size = 0;
};

nxdf nxdf_from_disk();
void nxdf_to_disk(nxdf* df);

nxdf nxdf_from_file(const char* file);
void nxdf_to_file(nxdf* df, const char* file);

#endif
