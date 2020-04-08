#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "GeneticAlgorithm.h"

GA::GA() : total(0), dRandom()
{
}

void GA::initChromos(std::vector<Equation>& original, std::vector<Equation>& temp)
{

	for (int i = 0; i < CHROMO_SIZE; i++)
	{
		GA::Equation e;
		for (int j = 0; j < VARIABLES; j++)
		{
			int randNum = randGenerate(0, 40);
			e.equation[j] = randNum;
			e.fit = 0;
		}

		original.push_back(e);
	}

	temp.resize(CHROMO_SIZE);
}

void GA::calcFitness(std::vector<Equation>& orginalCh)
{
	for (int i = 0; i < CHROMO_SIZE; i++)
	{

		int j = 0;
		orginalCh[i].evaluation = (float)abs((orginalCh[i].equation[j] + 2 * orginalCh[i].equation[j + 1]
			+ 3 * orginalCh[i].equation[j + 2] + 4 * orginalCh[i].equation[j + 3]) - 4);

	}
}

void GA::selectFitness(std::vector<Equation>& orginalCh)
{
	for (int i = 0; i < CHROMO_SIZE; i++)
	{
		orginalCh[i].fit = 1 / (1 + orginalCh[i].evaluation);
		total += orginalCh[i].fit;
	}

	float pro = 0;
	for (int i = 0; i < CHROMO_SIZE; i++)
	{
		pro += orginalCh[i].fit / total;
		orginalCh[i].probability = pro;
	}

}

void GA::copyFromP1toP2(std::vector<Equation>& p1, std::vector<Equation>& p2, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < VARIABLES; j++)
		{
			p2[i].equation[j] = p1[i].equation[j];
		}

		p2[i].fit = p1[i].fit;
	}
}

void GA::mutate(std::vector<Equation>& parent2, int i)
{

	int index1 = randGenerate(0, VARIABLES - 1);
	int index2 = randGenerate(0, VARIABLES - 1);

	int j = randGenerate(0, CHROMO_SIZE - 1);


	parent2[i].equation[index1] = parent2[j].equation[index2];


}

void GA::mate(std::vector<Equation>& parent1, std::vector<Equation>& parent2)
{

	int sub, p1, p2, p3, tSsize = VARIABLES;

	copyFromP1toP2(parent1, parent2, CHROMO_SIZE);

	for (int i = 0; i < CHROMO_SIZE; i++)
	{
		p1 = randGenerate(0, CHROMO_SIZE - 1);
		p2 = randGenerate(0, CHROMO_SIZE - 1);;
		p3 = randGenerate(0, CHROMO_SIZE - 1);
		sub = randGenerate(0, VARIABLES - 1);

		for (int j = sub; j < VARIABLES; j++)
		{
			parent2[p2].equation[j] = abs(parent1[p1].equation[j] - parent1[p3].equation[j]);
		}

		if (parent2[i].evaluation > 0.5f)
			mutate(parent2, i);
	}


}

bool GA::sortFitness(Equation x, Equation y)
{
	return(x.fit > y.fit);
}

void GA::sortByFitness(std::vector<Equation>& orginalCh)
{
	std::sort(orginalCh.begin(), orginalCh.end(), &GA::sortFitness);
}

void GA::swap(std::vector<GA::Equation>*& parent1, std::vector<GA::Equation>*& parent2)
{
	std::vector<GA::Equation>* temp = parent1;
	parent1 = parent2;
	parent2 = temp;
}

void GA::print(std::vector<Equation>& originalCh)
{
	for (int i = 0; i < VARIABLES; i++)
	{
		std::cout << originalCh[0].equation[i] << ", ";
	}

	std::cout << " fitness = " << originalCh[0].fit;
	std::cout << std::endl;
}

int GA::randGenerate(int start, int end)
{
	std::uniform_int_distribution<int> genenNum(start, end - 1);

	return genenNum(dRandom);
}

int main()
{

	GA ga;
	std::vector<GA::Equation> chromO, chromT;
	std::vector<GA::Equation>* originalCh, * bufferCh;

	ga.initChromos(chromO, chromT);

	originalCh = &chromO;
	bufferCh = &chromT;

	for (int i = 0; i < 2000; i++)
	{
		ga.calcFitness(*originalCh);
		ga.selectFitness(*originalCh);
		ga.sortByFitness(*originalCh);
		ga.print(*originalCh);

		if ((*originalCh)[0].fit == 1) break;

		ga.mate(*originalCh, *bufferCh);
		ga.swap(*&originalCh, *&bufferCh);

	}

	std::cin.get();

	return 0;
}