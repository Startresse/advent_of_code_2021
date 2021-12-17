#pragma once

#include <exception>

#include <iostream>
#include <fstream>

#include <vector>

class FileReader
{
public:
	static std::ifstream open(std::string filename);
};

