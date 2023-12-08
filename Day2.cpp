class Day2
{
private:
	std::regex reg, numReg;
	std::fstream file;
	std::sregex_iterator end;
	int currentSum;
public:	
	Day2()
	{
		file.open("text2.txt");
		currentSum = 0;
		reg = ("[0-9]*[ ]*[A-Z]*[a-z]+[ ]*[0-9]*");
		numReg = ("[0-9]+");
	}
	int solution_pt1()
	{
		std::string currentString, temp;
		std::smatch match, numMatch;
		int currentMatch = 0, matchSum = 0;
		bool flag;
		while (getline(file, currentString))
		{
			flag = 1;
			std::sregex_iterator iter(currentString.begin(), currentString.end(), reg);
			match = *iter;
			temp = match[0].str();
			(void)std::regex_search(temp, numMatch, numReg);
			currentMatch = std::stoi(numMatch.str());
			std::cout << "\t" << currentMatch << "\t\n";
			++iter;
			matchSum += currentMatch;
			while (iter != end)
			{
				match = *iter;
				std::cout << match[0] << "\n";
				temp = match[0].str();
				switch (temp[temp.size() - 1])
				{
				case 'd':
					(void)std::regex_search(temp, numMatch, numReg);
					if (std::stoi(numMatch[0].str()) > 12)
					{
						flag = 0;
						std::cout << "red exceeds number of cubes\n";
					}
					break;
				case 'n':
					(void)std::regex_search(temp, numMatch, numReg);
					if (std::stoi(numMatch[0].str()) > 13)
					{
						flag = 0;
						std::cout << "green exceeds number of cubes\n";
					}
					break;
				case 'e':
					(void)std::regex_search(temp, numMatch, numReg);
					if (std::stoi(numMatch[0].str()) > 14)
					{
						flag = 0;
						std::cout << "blue exceeds number of cubes\n";
					}
					break;
				}
				++iter;
				if (!flag)
				{
					matchSum -= currentMatch;
					break;
				}
			}
		}
		return matchSum;
	}
	int solution_pt2()
	{
		std::string currentString, temp;
		std::smatch match, numMatch;
		int rMax, gMax, bMax, power;
		long long powSum = 0;
		while (getline(file, currentString))
		{
			rMax = gMax = bMax = 0;
			std::sregex_iterator iter(currentString.begin(), currentString.end(), reg);
			++iter;
			while (iter != end)
			{
				match = *iter;
				std::cout << match[0] << "\n";
				temp = match[0].str();
				(void)std::regex_search(temp, numMatch, numReg);
				switch (temp[temp.size() - 1])
				{
				case 'd':
					if (std::stoi(numMatch[0].str()) > rMax)
					{
						rMax = std::stoi(numMatch[0].str());
					}
					break;
				case 'n':
					if (std::stoi(numMatch[0].str()) > gMax)
					{
						gMax = std::stoi(numMatch[0].str());
					}
					break;
				case 'e':
					if (std::stoi(numMatch[0].str()) > bMax)
					{
						bMax = std::stoi(numMatch[0].str());
					}
					break;
				}
				++iter;
			}
			power = rMax * gMax * bMax;
			powSum += power;
			std::cout << "rMax: " << rMax << " gMax: " << gMax << " bMax: " << bMax << " power: " << power << "\n";
		}
		return powSum;
	}
};
