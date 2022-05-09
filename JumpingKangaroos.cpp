// JumpingKangaroos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const static int MAX_INT = INT_MAX;

bool isCompleteable(std::vector<int> numbers) {

	for (int i = 0; !numbers.empty() && i < numbers[0]; i++)
	{
		if (i == numbers.size() - 1)
			return true;

		if (numbers[0] == 0)
			return false;

		if (numbers[0] - i < numbers.size())
		{
			std::vector<int> vec{
				numbers.begin() + numbers[0] - i, numbers.end()
			};

			if (isCompleteable(vec))
				return true;
		}
	}

	return false;
}

int getMinimalNumberOfJumps(std::vector<int> numbers) {

	int minimal = INT32_MAX;

	for (int i = 0; !numbers.empty(); i++)
	{
		if (numbers.size() == 1)
			return INT32_MAX;

		if (numbers[0] == 0)
			return 0;

		int temp;

		if(numbers[0] - i == 0)
			break;

		if (numbers[0] - i < numbers.size())
		{
			std::vector<int> vec{
				numbers.begin() + (numbers[0] - i), numbers.end()
			};

			temp = getMinimalNumberOfJumps(vec);
		}
		else
			temp = 0;

		if (temp < minimal && temp > 0)
			minimal = temp;
		else if (temp == INT32_MAX)
			minimal = 0;
	}

	return minimal == INT32_MAX ? 0 : minimal + 1;
}

int main()
{
	std::vector<int> numbers { 2, 3, 2, 1, 1, 2 };

	cout << isCompleteable(numbers) << endl;
	cout << getMinimalNumberOfJumps(numbers) << endl;

	return EXIT_SUCCESS;
}
