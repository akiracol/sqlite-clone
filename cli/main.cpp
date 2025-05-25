#include <fstream>
#include <iostream>

enum InputType {
    EXIT,
    HELP,
    OTHER,
    QUERY
};


int main() {
    std::cout << "Hello and welcome to my FOSS c++ sqlite clone!\n";
    std::string input;
    while (true) {
        std::cout << "Please enter a command: (exit, help)\n";
        std::getline(std::cin, input);

        if (input.at(0) == '-') {
            switch (input) {
                case EXIT:
                    return EXIT_SUCCESS;

                case HELP: {
                    std::cout << "Syntax TBD";
                    continue;
                }
                case QUERY: {
                    std::cout << "Syntax TBD";
                    continue;
                }
            }
            continue;
        } else {
            std::cout << "Unknown command: " << input << "\n";
        }

        Statement statement;

        switch (prepare_statement(input, statement)) {
            case (PREPARE_SUCCESS):
                break;

            case (PREPARE_UNRECOGNIZED_STATEMENT):
                std::cout << "unrecognized keyword at the start of '%s'.\n" << input;
                continue;
        }

        execute_statement(statement);
        std::cout << "Executed.\n";
    }

    return 0;
}