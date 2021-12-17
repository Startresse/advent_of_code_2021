#include "Day1.h"

void Day1::run() const
{
    auto file = FileReader::open("input_d1");

    std::vector<int> values;
    int value;
    while (file >> value)
    {
        values.push_back(value);
    }

    file.close();

    int count = 0;
    for (int i = 0; i < values.size() - 3; ++i)
    {
        if (values[i] + values[i + 1] + values[i + 2] < values[i + 1] + values[i + 2] + values[i + 3])
            count++;
    }

    std::cout << count << std::endl;
}
