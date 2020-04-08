#include <vector>
#include <random>

//the variables in the equation, which represnts the (a,b,c,d)
const int VARIABLES = 4;
//the size of chromosoms population
const int CHROMO_SIZE = 10000;

class GA
{

public:
	struct Equation
	{
		int equation[VARIABLES];
		float evaluation;
		float fit;
		float probability;
	};

public:
	GA();
	//initialize the chromosoms
	void initChromos(std::vector<Equation>& original, std::vector<Equation>& temp);

	//calculate the fitness of chromosoms
	void calcFitness(std::vector<Equation>& orginalCh);

	//select the fit ones
	void selectFitness(std::vector<Equation>& orginalCh);

	//copy from parent one to parent two
	void copyFromP1toP2(std::vector<Equation>& parent1,
		std::vector<Equation>& parent2, int size);

	//mutate the chromosoms and select two chromosoms to mate
	void mutate(std::vector<Equation>& parent2, int i);
	void mate(std::vector<Equation>& parent1, std::vector<Equation>& parent2);

	//sort chromosoms by fitness
	bool static sortFitness(Equation x, Equation y);
	void sortByFitness(std::vector<Equation>& orginalCh);

	//swap parent one and parent two for the next generation
	void swap(std::vector<Equation>*& parent1, std::vector<Equation>*& parent2);

	//print the best fit of every generation
	void print(std::vector<Equation>& originalCh);

	//generate random number
	int randGenerate(int start, int end);

public:
	std::default_random_engine dRandom;

private:
	float total;

};
