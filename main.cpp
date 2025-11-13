#include "parser.h"
#include "generation.h"
#include "out.h"

int main (int argc, char *argv[]) {
    pars::parser parsing;
    if (!parsing.input(argc, argv)) {
        std::cout << "Write: ./hatch_generator --angle *num* --step *num*" << "\n";
        return 1;
    }
    if (!parsing.massive()) {
        std::cout << "Write: one point *num* *num* and press enter for write next numbers" << "\n";
    }

    gen::generation generationfig(std::atof(argv[2]), std::atof(argv[4]), parsing.getPoints());

    generationfig.generate();
    outs::out::printRes(generationfig.getLines());

    return 0;
}