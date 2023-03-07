using namespace std;
#include <iostream>
template <typename T> class Matrix {
private:
    T arr[4][4];
public:
    Matrix<T>() {
        cout << "A matrix object has been created.\n";
    }
    void isQuattro() {
        T zero_zero = arr[0][1] + arr[1][0] + arr[1][1];
        T zero_three = arr[0][2] + arr[1][2] + arr[1][3];
        T three_zero = arr[2][0] + arr[2][1] + arr[3][1];
        T three_three = arr[2][2] + arr[2][3] + arr[3][2];
        if ((zero_zero == arr[0][0]) && (zero_three == arr[0][3]) && (three_zero == arr[3][0]) && (three_three == arr[3][3])) {
            cout << "This is a Quattro Matrix.\n";
        }
    }
    ~Matrix() {
        cout << "A matrix object has been destroyed.\n";
    }
    friend istream& operator>>(istream& input, Matrix& matrix) {
        for (int i = 0; i < 4; i++) {
            cout << "Input row " << (i + 1) << ":" << endl;
            for (int j = 0; j < 4; j++) {
                input >> matrix.arr[i][j];
                if ((matrix.arr[i][j] > 25) || (0 > matrix.arr[i][j])) {
                    cout << "Number not between 0-25. Assigning random number instead.";
                    matrix.arr[i][j] = rand() % 26;
                }
            }
        }
        return input;
    }
    friend ostream& operator<<(ostream& output, Matrix& matrix) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                output << matrix.arr[i][j] << " ";
            }
            output << endl;
        }
        return output;
    }
    Matrix operator+ (const Matrix& matrix) {
        Matrix result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.arr[i][j] = this->arr[i][j] + matrix.arr[i][j];
            }
        }
        return result;
    }
    Matrix operator- (const Matrix& matrix) {
        Matrix result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.arr[i][j] = this->arr[i][j] - matrix.arr[i][j];
            }
        }
        return result;
    }
};

int main()
{
    Matrix<int> m1, m2, m3;
    cout << "Input the first matrix:\n\n";
    cin >> m1;
    cout << "Input the second matrix:\n\n";
    cin >> m2;
    cout << "Which operation would you like to do? (+ or -)";
    char operation;
    cin >> operation;
    switch (operation) {
        case '+':
            m3 = m1 + m2;
            break;
        case '-':
            m3 = m1 - m2;
            break;
    }
    cout << m3;
    m3.isQuattro();
    return 0;
}