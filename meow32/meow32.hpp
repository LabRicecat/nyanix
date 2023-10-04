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
#include <set>
#include <functional>

namespace meow32 {
    struct program {
        unit_t* source = nullptr;
        unit_t size = 0;
    };

    struct label {
        unit_t position = 0;
        bool local = false;
    };

    struct snippet {
        std::vector<unit_t> source;
    };

    struct asmstate {
        std::map<std::string, label> labels;
        std::map<std::string, std::vector<unit_t>> unresolved;
    };

    struct directive {
        long args = 0; // <0 -> va-args
        std::function<snippet(std::vector<std::string>, asmstate&)> perform;
    };

    std::vector<std::string> linify(const std::string& source);
    program assemble(const std::string& source);

    inline std::map<std::string, directive> directives;

}
