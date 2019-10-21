#include "Shrek.h"

float sigmoid(float _x);

float sigmoidDerivative(float _x);

Shrek::Shrek()
{
	srand(1);
	for (int loop = 0; loop < 2; loop++)
	{
		for (int loop2 = 0; loop2 < 4; loop2++)
		{
			m_weights1[loop][loop2] = ((float)(rand()) / (float)(RAND_MAX / 2)) - 1;
		}
	}
	for (int loop = 0; loop < 3; loop++)
	{
		m_weights2[loop] = ((float)(rand()) / (float)(RAND_MAX / 2)) - 1;
	}
}


Shrek::~Shrek()
{
}


float Shrek::think(glm::vec4 _input, int _dataSet)
{
	float B1 = sigmoid(glm::dot(_input, m_weights1[0]));
	float B2 = sigmoid(glm::dot(_input, m_weights1[1]));
	m_B[_dataSet] = { 1,B1,B2 };
	return sigmoid(glm::dot(m_B[_dataSet], m_weights2));
}

void Shrek::train(float _trueOutput[4])
{
	float adjustments[4];
	for (int loop = 0; loop < 4; loop++)
	{
		m_output[loop] = this->think(m_inputs[loop], loop);
	}
	for (int loop2 = 0; loop2 < 4; loop2++)
	{
		float error = _trueOutput[loop2] - m_output[loop2];
		adjustments[loop2] = error * sigmoidDerivative(m_output[loop2]);
	}
	for (int loop = 0; loop < 2; loop++)
	{
		for (int loop2 = 0; loop2 < 4; loop2++)
		{
			m_weights1[loop][loop2] += (m_inputs[0][loop2] * adjustments[0] * m_B[loop2][loop + 1])
				+ (m_inputs[1][loop2] * adjustments[1] * m_B[loop2][loop + 1])
				+ (m_inputs[2][loop2] * adjustments[2] * m_B[loop2][loop + 1])
				+ (m_inputs[3][loop2] * adjustments[3] * m_B[loop2][loop + 1]);
		}
	}
	for (int loop = 0; loop < 3; loop++)
	{
		m_weights2[loop] += (m_B[0][loop] * adjustments[0]) + (m_B[1][loop] * adjustments[1]) + (m_B[2][loop] * adjustments[2]) + (m_B[3][loop] * adjustments[3]);
	}
}


void Shrek::output()
{
	std::cout << "Weights after training: " << m_weights1[0][0] << " " << m_weights1[0][1] << " " << m_weights1[0][2] << " " <<  m_weights1[0][3] << std::endl;
	std::cout << "Weights after training: " << m_weights1[1][0] << " " << m_weights1[1][1] << " " << m_weights1[1][2] << " " << m_weights1[1][3] << std::endl;
	std::cout << "Weights after training: " << m_weights2[0] << " " << m_weights2[1] << " " << m_weights2[2] << std::endl;
	std::cout << "Test case: " << this->think(glm::vec4(1, 0, 0, 1),0) << std::endl;
}

float sigmoid(float _x)
{
	return 1 / (1 + exp(-_x));
}

float sigmoidDerivative(float _x)
{
	return sigmoid(_x) * (1 - sigmoid(_x));
}