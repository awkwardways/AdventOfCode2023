class Day3
{
private:
	std::fstream file;
	struct numCoord
	{
		int x, y, num, size;
	};
	std::stack<numCoord> numberPositions;
	bool symbolMatrix[140][140];
	int isSymbol(std::string symbol, int x, int y);
	int parseNum(std::string num, int fpos, int yPos);
	void savePos(int x, int y);
	int findAdj();
public:
	Day3()
	{
		for (int i = 0; i < 140; i++)
		{
			for (int j = 0; j < 140; j++)
			{
				symbolMatrix[i][j] = 0;
			}
		}
		file.open("text3.txt");
	}
	int solution()
	{
		std::string currentString;
		int x = 0, y = 0;
		bool previousIsSymbol = 0;
		while (getline(file, currentString))
		{
			for(x = 0; x < currentString.size(); x++)
				x += isSymbol(currentString, x, y);
			y++;
		}
		return findAdj();
	}
};

//Day 3 prototype definition
int Day3::isSymbol(std::string symbol, int x, int y)
{
	if (symbol[x] != '.')
	{
		if (symbol[x] > 57 || symbol[x] < 48)
		{
			savePos(x, y);
			return 0;
		}
		else
		{
			return parseNum(symbol, x, y);
		}
	}
	return 0;
}

int Day3::parseNum(std::string num, int fPos, int yPos)
{
	int i = fPos, size = 1;
	numCoord number;
	std::string subStringNum("");
	while (num[i] <= 57 && num[i] >= 48)
	{
		subStringNum.push_back(num[i]);
		++i;
		size++;
	}
	number = {i - 1, yPos, std::stoi(subStringNum), size - 1};
	numberPositions.push(number);
	return (size - 2);
}

void Day3::savePos(int x, int y)
{
	symbolMatrix[y][x] = 1;
	return;
}

int Day3::findAdj()
{
	numCoord currentNum;
	int sum = 0;
	bool adjFound = 0;
	while (!numberPositions.empty())
	{
		currentNum = numberPositions.top();
		numberPositions.pop();
		if (currentNum.y > 0)
		{
			for (int i = currentNum.x + 1; i >= currentNum.x - currentNum.size; i--)
			{
				if (i < 0)
					break;
				if (i > 139)
					i--;
				if (symbolMatrix[currentNum.y - 1][i])
				{
					sum += currentNum.num;
					adjFound = 1;
					break;
				}
			}
		}
		if (currentNum.y < 139 && !adjFound)
		{
			for (int i = currentNum.x + 1; i >= currentNum.x - currentNum.size; i--)
			{
				if (i < 0)
					break;
				if (i > 139)
					i--;
				if (symbolMatrix[currentNum.y + 1][i])
				{
					sum += currentNum.num;
					adjFound = 1;
					break;
				}
			}
		}
		if (!adjFound && currentNum.x > (currentNum.size - 1))
		{
			if (symbolMatrix[currentNum.y][currentNum.x - currentNum.size])
			{
				sum += currentNum.num;
				adjFound = 1;
			}
		}
		if (!adjFound && currentNum.x < 139)
		{
			if (symbolMatrix[currentNum.y][currentNum.x + 1])
			{
				sum += currentNum.num;
				adjFound = 1;
			}
		}
		adjFound = 0;
	}
	return sum;
}
