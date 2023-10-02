/*

grammar:

LABEL:
    name args...
.LOCAL:
    [deref]
    [offset+1]

*/

#include "../disk.hpp"

#include <string>
#include <map>
#include <vector>

namespace meow32 {
    struct program {
        unit_t* source = 0;
        unit_t size = 0;
    };

    std::vector<std::string> linify(const std::string& source);

    program assemble(const std::string& source);

}
