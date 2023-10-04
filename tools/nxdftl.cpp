#include "../nxdf/nxdf.hpp"
#include "../debug.hpp"

#include <string>
#include <iostream>

#define declarg(str, args) \
    if(argc == args+2 && arg == str)

int main(int argc, char** argv) {
    if(argc <= 2) return 0;
    std::string file = std::string(argv[1]);
    std::string arg = std::string(argv[2]);

    nxdf df = nxdf_from_file(file.c_str());

    declarg("dump", 1) {
        nxdf_display(&df);
    }

    declarg("diskinfo", 1) {
        nxdf_to_disk(&df);
        diskinfo();
    }

    delete[] df.file;

}

