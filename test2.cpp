#include <iostream>

using namespace std;

int factorial(int n) {
    // Base case: Stops the recursion
    if (n == 0) {
        return 1;
    } 
    // Recursive case: Calls itself with n-1
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 5;
    cout << "Factorial of " << number << " is: " << factorial(number) << endl;
    // Output for 5 is 120
    return 0;
}
