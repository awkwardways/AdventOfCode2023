class Day4
{
private:
	int sumArr[208];
	std::fstream file;
public:
	Day4()
	{
		file.open("text4.txt");
		for (int i = 0; i < 208; i++)
		{
			sumArr[i] = 1;
		}
	}
	int solution()
	{
		std::unordered_map<int, bool> winningNumbers;
		int temp;
		int val = 1;
		long long i = 0, sum = 0;
			while (i < 208)
			{
				val = 1;
				val = val << 24;
				for (int i = 0; i < 10; i++)
				{
					file >> temp;
					winningNumbers[temp] = 1;
					//std::cout << temp << " ";
				}
				for (int i = 0; i < 25; i++)
				{
					file >> temp;
					if (!winningNumbers[temp])
					{
						val = val >> 1;
					}
				}
				i++;
				sum += val;
				winningNumbers.clear();
			}
		std::cout << sum << "\n";
		return 0;
	}
	int solutionpt2()
	{
		int i = 0, temp;
		int matches = 0;
		long long sum = 0;
		std::unordered_map<int, bool> winningNumbers;
		while (i < 208)
		{
			for (int j = 0; j < 10; j++)
			{
				file >> temp;
				winningNumbers[temp] = 1;
				//std::cout << temp << " ";
			}
			for (int j = 0; j < 25; j++)
			{
				file >> temp;
				if (winningNumbers[temp])
				{
					matches++;
				}
			}
			for (int j = i + 1; j <= matches + i; j++)
			{
				sumArr[j] += sumArr[i];
			}
			sum += sumArr[i];
			++i;
			winningNumbers.clear();
			matches = 0;
		}
		return sum;
	}
};
