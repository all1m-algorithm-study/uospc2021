#include "testlib.h"
#include <cstdlib>
#include <string>

const std::string TOKENS = "UOSPC";

std::string generateLine(int length) {
    std::string line = "";
    for (int i = 0; i < length; ++i) {
        line += TOKENS[rnd.next(0, int(TOKENS.size()-1))];
    }
    return line;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);

    std::cout << n1 << " " << n2 << "\n";
    std::cout << generateLine(n1) << "\n";
    std::cout << generateLine(n2) << "\n";

    return 0;
}
