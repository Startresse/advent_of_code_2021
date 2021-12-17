#include "Day2.h"

void Day2::run() const
{
    auto file = FileReader::open("input_d2");

    std::string dir;
    int val;
    std::vector<std::pair<std::string, int>> vec;
    while (file >> dir >> val)
        vec.emplace_back(dir, val);

    file.close();

    int dist = 0;
    int depth = 0;
    int aim = 0;

    for (auto x : vec)
    {
        if (x.first == "forward")
        {
            dist += x.second;
            depth += x.second * aim;
        }
        else if (x.first == "down")
            aim += x.second;
        else if (x.first == "up")
            aim -= x.second;
    }

    std::cout << dist * depth << std::endl;

}
