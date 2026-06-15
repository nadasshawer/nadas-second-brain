#include <iostream>

using namespace std;

int main()
{
    int A[5];
    A[0] = 10;
    A[1] = 15;
    A[2] = 20;

    cout << sizeof(A) << endl;  // 20 (4 * 5)
    cout << A[1] << endl;   // 15

    return 0;
}