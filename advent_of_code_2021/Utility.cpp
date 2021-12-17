#include "Utility.h"

std::ifstream FileReader::open(std::string s)
{
	std::ifstream file;

    file.open(s);
    if (!file.is_open()) {
        // throw std::invalid_argument("Couldn't open file");
        std::cout << "Couldn't open file" << std::endl;
        exit(0);
    }

    return file;
}
