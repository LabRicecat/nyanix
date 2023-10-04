#include "nxdf.hpp"
#include "../disk.hpp"

#include <bits/types/FILE.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

long nchunk(size_t last) {
    size_t current = 0;
    for(size_t i = 0; i < NYANIX_DISK_SIZE / NYANIX_CHUNK_SIZE; ++i)
        if(disk[i] != nullptr) {
            if(current < last)
                ++current;
            else 
                return i;
        }

    return -1;
}

nxdf nxdf_from_disk() {
    const size_t chunk_s = NYANIX_CHUNK_SIZE * sizeof(unit_t); 
    const size_t chunk_off = sizeof(unit_t);
    const size_t start_off = 4 + sizeof(nxdfs_t);

    nxdf df;
    df.size = NYANIX_NXDF_DISKSTART;
    df.size += dchunked() * chunk_s;
    df.file = new char[df.size];
    if(!df.file) 
        return df;

    // magic numbers
    df.file[0] = NYANIX_NXDF_MAGIC0;
    df.file[1] = NYANIX_NXDF_MAGIC1;
    df.file[2] = NYANIX_NXDF_MAGIC2;
    df.file[3] = NYANIX_NXDF_MAGIC3;

    memcpy(df.file + 4, (char*)&df.size, sizeof(nxdfs_t)); 
   
    df.file += start_off;

    for(size_t last_chunk = 0; last_chunk < dchunked(); ++last_chunk) {
        long chunk = nchunk(last_chunk);
        if(chunk < 0) break;
    
        const unit_t chunk_position = last_chunk * (chunk_s + chunk_off);

        memcpy(df.file + chunk_position, (void*)&chunk_position, chunk_off);
        memcpy(df.file + chunk_position + chunk_off, disk[chunk], chunk_s);
    }

    df.file -= start_off;

    return df;
}

bool nxdf_valid(nxdf* df) {
    if(df->size < 4 + sizeof(nxdfs_t)) return false;
    if((df->size - 4 + sizeof(nxdfs_t)) % (NYANIX_CHUNK_SIZE * sizeof(unit_t) + sizeof(nxdfs_t)) != 0) return false;

    char* magic = new char[4];
    memcpy(magic, df->file, 4);

    bool res = 
            magic[0] == NYANIX_NXDF_MAGIC0 &&
            magic[1] == NYANIX_NXDF_MAGIC1 &&
            magic[2] == NYANIX_NXDF_MAGIC2 &&
            magic[3] == NYANIX_NXDF_MAGIC3;

    delete[] magic;
    return res;
}

void nxdf_to_disk(nxdf* df) {
    if(!nxdf_valid(df)) return;

    df->file += 4 + sizeof(nxdfs_t);
    df->size -= 4 + sizeof(nxdfs_t);
    
    nxdfs_t size = 0;

    for(nxdfs_t i = 0; i < df->size; ) {
        memcpy((char*)&size, df->file + i, sizeof(nxdfs_t));
        memcpy(disk[size], df->file + i + sizeof(nxdfs_t), NYANIX_CHUNK_SIZE);

        i += NYANIX_CHUNK_SIZE + sizeof(nxdfs_t);
    }

    df->file -= 4 + sizeof(nxdfs_t);
    df->size -= 4 + sizeof(nxdfs_t);
}

nxdf nxdf_from_file(const char* file) {
    nxdf df;
    
    FILE* f = fopen(file, "r");
    fseek(f, 0L, SEEK_END);
    size_t sz = ftell(f);
    rewind(f);

    df.file = new char[sz];
    df.size = sz;

    fread(df.file, 1, sz, f);

    fclose(f);
    return df;
}

void nxdf_to_file(nxdf* df, const char* file) {
    FILE* f = fopen(file, "w");
    fwrite(df->file, 1, df->size, f);
    fclose(f);
}

