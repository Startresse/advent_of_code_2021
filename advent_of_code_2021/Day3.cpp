#include "Day3.h"

long long convert(std::vector<int> s)
{
	long long res = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		res += pow(2, i) * s[s.size() - i - 1];
	}
	return res;
}

void display(std::vector<int> s)
{
	for (int x : s)
		std::cout << x;
	std::cout << " (converted : " << convert(s) << ")" << std::endl;
}

void Day3::run() const
{
	auto file = FileReader::open("input_d3");

	std::vector<std::string> lines;
	std::string val;
	while (file >> val)
	{
		lines.push_back(val);
	}
	file.close();

	int length = lines[0].length();
	std::vector<int> gamma_rate(length, 0);
	std::vector<int> epsilon_rate(length, 1);

	std::vector<int> oxygen_generator_rating(length, 0);
	std::vector<int> co2_scrubber_rating(length, 1);

	for (int i = 0; i < length; ++i)
	{
		int num1 = 0;
		for (int j = 0; j < lines.size(); ++j)
		{
			num1 += lines[j][i] == '1';
		}

		if (num1 >= lines.size() / 2)
		{
			gamma_rate[i] = 1;
			epsilon_rate[i] = 0;
		}
	}


	std::cout << "Gamma : ";
	display(gamma_rate);

	std::cout << "Epsilon : ";
	display(epsilon_rate);

	long long gamma_value = convert(gamma_rate);
	long long epsilon_value = convert(epsilon_rate);
	std::cout << "Power consumption rate : " << gamma_value * epsilon_value << std::endl;

}
