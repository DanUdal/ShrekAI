#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string_cast.hpp>
#include <transform.hpp>

class Shrek
{
private:
	glm::vec4 m_inputs[4]{ {1,1,1,0}, {1,0,0,1}, {1,0,1,0}, {1,0,1,1} };
	glm::mat2x4 m_weights1;
	glm::vec3 m_weights2;
	glm::vec3 m_layer2{ 1,0,0 };
	glm::vec3 m_B[4]{ {0,0,0}, {0,0,1}, {0,1,0}, {0,1,1} };
	float m_output[4];
public:
	Shrek();
	~Shrek();
	float think(glm::vec4 _input, int _dataSet);
	void train(float _trueOutput[4]);
	void output();
};

