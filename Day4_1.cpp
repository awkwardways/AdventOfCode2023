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
