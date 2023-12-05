#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<unordered_map>

int main()
{
	std::unordered_map<std::string, int> lookUpTable;
	lookUpTable.insert({
		{"0",0},
		{"1",1},
		{"2",2},
		{"3",3},
		{"4",4},
		{"5",5},
		{"6",6},
		{"7",7},
		{"8",8},
		{"9",9}
		});
	std::fstream file("text.txt");
	std::string currentString;
	std::regex reg("(0|1|2|3|4|5|6|7|8|9)");
	std::regex r_reg("(0|1|2|3|4|5|6|7|8|9)");
	std::match_results<std::string::const_reverse_iterator> rmatch;
	std::sregex_iterator end;
	int currentSum = 0;

	while (getline(file, currentString))
	{
		std::sregex_iterator iter(currentString.begin(), currentString.end(), reg);
		std::smatch match;
		for (iter; iter != end && match.empty(); iter++)
		{
			match = *iter;
			currentSum += lookUpTable[match[0]] * 10;
		}
		(void)std::regex_search(currentString.crbegin(), currentString.crend(), rmatch, r_reg);
		currentSum += lookUpTable[rmatch[0]];
	}
	std::cout << currentSum;
	return 0;
}
