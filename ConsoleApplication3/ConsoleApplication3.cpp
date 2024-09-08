#include <iostream>
#include "Matrix.cpp"

int main()
{

	Matrix<int> matrix1(3, 3);
	matrix1.random_init();
	std::cout << "Array 1:\n" << matrix1 << std::endl;
	
	Matrix<int> matrix2(3, 3);
	matrix2.random_init();
	std::cout << "Array 2:\n" << matrix2 << std::endl;

	std::cout << "Min: " << matrix1.find_minimum() << std::endl;

	std::cout << "Max: " << matrix1.find_maximum() << std::endl;
	
	Matrix<int> matrix3 = matrix1 + matrix2;
	std::cout << "Sum:\n" << matrix3 << std::endl;

	Matrix<int> matrix4 = matrix1 - matrix2;
	std::cout << "Minus:\n" << matrix4 << std::endl;

	Matrix<int> matrix5 = matrix1 * matrix2;
	std::cout << "Multy:\n" << matrix5 << std::endl;

	Matrix<int> matrix6 = matrix1 / matrix2;
	std::cout << "Divide:\n" << matrix6 << std::endl;

}



