#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

//На основе арифметической прогрессии составлен список натуральных чисел. К списку добавили одно число, уже имеющееся в нем, и потом список перемешали.
//Найти: границы прогрессии, шаг и добавленное число.

void exploreSequence(std::vector<int> arith_seq)
{
	if (arith_seq.empty())
		return;

	std::sort(arith_seq.begin(), arith_seq.end());

	std::map<int, int> s_map;

	int added_element = 0;

	for(auto i = arith_seq.begin(); i != arith_seq.end(); i++)
	{
		auto k = *i;
		s_map[k]++;
		if(s_map[k] == 2)
		{
			added_element = k;
			break;
		}
	}

	auto begin = arith_seq.cbegin(); // указатель на первый элемент
	auto end = arith_seq.back();     // указатель на последний элемент

	int progression_step = arith_seq[1] - arith_seq[0];

	char result[100];
	auto p = snprintf(result, sizeof(result), "Begin: %d, End: %d, Step: %d, Added element: %d", *begin, end, progression_step, added_element);
	std::cout << result << std::endl;
}

int main()
{
    std::cout << "Hello World!\n";

	std::vector<int> a = {13, 3, 9, 7, 15, 1, 5, 3, 11};

	exploreSequence(a);
}