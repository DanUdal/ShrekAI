#include "Shrek.h"

int main()
{
	Shrek brain;
	float testOutputs[4]{ 0,1,0,1 };
	for (int loop = 0; loop < 500000; loop++)
	{
		brain.train(testOutputs);
	}
	brain.output();
	glm::ivec4 inputs;
	inputs[0] = 1;
	std::cout << "Enter your own test input" << std::endl;
	for (int loop = 1; loop < 4; loop++)
	{
		std::cin >> inputs[loop];
	}
	float output = brain.think(inputs,0);
	std::cout << "The network believes the answer is " << output;
	std::cin.get();
	std::cin.get();
	return 0;
	return 0;
}