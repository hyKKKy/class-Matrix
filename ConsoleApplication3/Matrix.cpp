#include <iostream>
#include<iostream>

template<typename T>
class Matrix
{
friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.ROW; i++) {
        for (int j = 0; j < matrix.COL; j++) {
            os << matrix.matrix[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

private:
	T** matrix;
	int COL;
	int ROW;
public:
	Matrix();

	Matrix(int ROW, int COL);

	~Matrix();

	void random_init();

	void print();

    void keyboard_init();

    T* operator[](int index);

    Matrix operator+(const Matrix& other);

    Matrix operator-(const Matrix& other);

    Matrix operator*(const Matrix& other);

    Matrix operator/(const Matrix& other);

    T find_minimum();

    T find_maximum();

};

template<typename T>
Matrix<T>::Matrix() {
    this->matrix = nullptr;
    this->COL = 0;
    this->ROW = 0;
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < ROW; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
Matrix<T>::Matrix(int ROW, int COL) {
    this->COL = COL;
    this->ROW = ROW;

    this->matrix = new T * [ROW];
    for (int i = 0; i < ROW; i++) {
        matrix[i] = new T[COL];
    }
}

template<typename T>
void Matrix<T>::random_init() {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            matrix[i][j] = rand() % 21;  
        }
    }
}

template<typename T>
void Matrix<T>::print() {

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void Matrix<T>::keyboard_init() {
    T value;

    for ( int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++) {
            std::cin >> value;
            matrix[i][j] = value;
        }
    }
}

template <typename T>
T* Matrix<T>::operator[](int index) {
    return matrix[index];
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) {
    if (this->ROW != other.ROW || this->COL != other.COL) {
        std::cout << "Error!";
    }
    
    Matrix<T> result(this->ROW, this->COL);
    for (int i = 0; i < this->ROW; i++) {
       for (int j = 0; j < this->COL; j++) {
          result[i][j] = this->matrix[i][j] + other.matrix[i][j];
       }
    }
    return result;
    
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& other) {
    if (this->ROW != other.ROW || this->COL != other.COL) {
        std::cout << "Error!";
    }

    Matrix<T> result(this->ROW, this->COL);
    for (int i = 0; i < this->ROW; i++) {
        for (int j = 0; j < this->COL; j++) {
            result[i][j] = this->matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;

}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) {
    if (this->ROW != other.ROW || this->COL != other.COL) {
        std::cout << "Error!";
    }

    Matrix<T> result(this->ROW, this->COL);
    for (int i = 0; i < this->ROW; i++) {
        for (int j = 0; j < this->COL; j++) {
            result[i][j] = this->matrix[i][j] * other.matrix[i][j];
        }
    }
    return result;

}

template<typename T>
Matrix<T> Matrix<T>::operator/(const Matrix& other) {
    if (this->ROW != other.ROW || this->COL != other.COL) {
        std::cout << "Error!";
    }

    Matrix<T> result(this->ROW, this->COL);
    for (int i = 0; i < this->ROW; i++) {
        for (int j = 0; j < this->COL; j++) {
            result[i][j] = this->matrix[i][j] / other.matrix[i][j];
        }
    }
    return result;

}

template<typename T>
T Matrix<T>::find_minimum() {
    T min = this->matrix[0][0];
    for (int i = 0; i < this->ROW; i++) {
        for (int j = 0; j < this->COL; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;  
}

template<typename T>
T Matrix<T>::find_maximum() {
    T max = this->matrix[0][0];
    for (int i = 0; i < this->ROW; i++) {
        for (int j = 0; j < this->COL; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}