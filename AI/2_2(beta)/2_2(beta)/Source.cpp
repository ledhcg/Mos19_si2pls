#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

#define variable 4 // bien so
#define chromoSize 100000 // kich thuoc nhiem sac the
float total = 0; //tong cong
struct Equation
{
	int eq[variable];
	float ev;
	float fit;
	float p;
};


void init_chrom(vector<Equation>& Original, vector<Equation>& Temp)
{
	for (int i = 0; i < chromoSize; i++)
	{
		Equation e;
		for (int j = 0; j < variable; j++)
		{
			e.eq[j] = rand() % 30;
			e.fit = 0;
		}

		Original.push_back(e);
	}

	Temp.resize(chromoSize);
}

void calc_fit(vector<Equation>& orginalCh)
{
	for (int i = 0; i < chromoSize; i++)
	{

		int j = 0;
		orginalCh[i].ev = abs((orginalCh[i].eq[j] + 2 * orginalCh[i].eq[j + 1] +
			3 * orginalCh[i].eq[j + 2] + 4 * orginalCh[i].eq[j + 3]) - 10);

	}
}

void select_fit(vector<Equation>& orginalCh)
{
	for (int i = 0; i < chromoSize; i++)
	{
		orginalCh[i].fit = 1 / (1 + orginalCh[i].ev);
		total += orginalCh[i].fit;
	}

	float pro = 0;
	for (int i = 0; i < chromoSize; i++)
	{
		pro += orginalCh[i].fit / total;
		orginalCh[i].p = pro;
	}

}

void _copy(vector<Equation>& p1, vector<Equation>& p2, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < variable; j++)
			p2[i].eq[j] = p1[i].eq[j];

		p2[i].fit = p1[i].fit;
	}
}

void mutate(vector<Equation>& parent2, int i)
{
	int size = variable;
	int index1 = rand() % size;
	int index2 = rand() % size;
	int j = rand() % chromoSize;

	parent2[i].eq[index1] = parent2[j].eq[index2];


}
void mate(vector<Equation>& parent1, vector<Equation>& parent2)
{

	int sub, p1, p2, tSsize = variable;

	_copy(parent1, parent2, chromoSize);

	for (int i = 0; i < chromoSize; i++)
	{
		p1 = rand() % chromoSize;
		p2 = rand() % chromoSize;
		sub = rand() % tSsize;

		for (int j = sub; j < variable; j++)
			parent2[p2].eq[j] = parent1[p1].eq[j];

		if (parent2[i].ev > 0.1f)
			mutate(parent2, i);
	}


}

bool sort_fitness(Equation x, Equation y)
{
	return(x.fit > y.fit);
}
void _sort(vector<Equation>& orginalCh)
{
	sort(orginalCh.begin(), orginalCh.end(), sort_fitness);
}
void swap(vector<Equation>*& parent1, vector<Equation>*& parent2)
{
	vector<Equation>* temp = parent1;
	parent1 = parent2;
	parent2 = temp;
}
void print(vector<Equation>& originalCh)
{
	for (int i = 0; i < variable; i++)
	{
		cout << originalCh[0].eq[i] << ", ";
	}

	cout << " " << originalCh[0].ev << " " << originalCh[0].fit;
	cout << endl;
}

int main()
{
	srand(unsigned(time(NULL)));

	vector<Equation> chromO, chromT;
	vector<Equation>* originalCh, * bufferCh;
	init_chrom(chromO, chromT);

	originalCh = &chromO;
	bufferCh = &chromT;

	for (int i = 0; i < 2000; i++)
	{
		calc_fit(*originalCh);
		select_fit(*originalCh);
		_sort(*originalCh);
		print(*originalCh);

		if ((*originalCh)[0].fit == 1) break;

		mate(*originalCh, *bufferCh);
		swap(*originalCh, *bufferCh);

	}

	system("pause");

	return 0;
}