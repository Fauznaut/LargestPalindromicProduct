#include <iostream>
#include <math.h>
#include <sstream>
using namespace std;

static int firstFactorDigits;
static int secondFactorDigits;
int LargestPalindromicProduct(int firstFactorDigits, int secondFactorDigits);

int main() {
    cout << "Enter the number of digits you want for the first factor:";
    cin >> firstFactorDigits;
    cout << "Enter the number of digits you want for the second factor:";
    cin >> secondFactorDigits;
    cout << "Largest Palindromic Product: " << LargestPalindromicProduct(firstFactorDigits, secondFactorDigits);
    return 0;
}

bool CheckForPalindrome(int product) {
    ostringstream productAsString;
    productAsString << product;
    string productParsedAsString = productAsString.str();
    int backwardsProductParsedAsStringPosition = productParsedAsString.length() - 1;
    string backwardsProductParsedAsString;
    for (int currentChar = 0; currentChar < productParsedAsString.length(); currentChar++) {
        backwardsProductParsedAsString += productParsedAsString.at(
                (unsigned int) backwardsProductParsedAsStringPosition);
        backwardsProductParsedAsStringPosition--;
    }
    return productParsedAsString == backwardsProductParsedAsString;
}

int LargestPalindromicProduct(int firstFactorDigits, int secondFactorDigits) {
    static int LargestPalindromicProduct = 0;
    for (int currentFirstProduct = 1; currentFirstProduct < pow(10, firstFactorDigits); currentFirstProduct++) {
        for (int currentSecondProduct = 1; currentSecondProduct < pow(10, secondFactorDigits); currentSecondProduct++) {
            if (CheckForPalindrome(currentFirstProduct * currentSecondProduct) && currentFirstProduct * currentSecondProduct > LargestPalindromicProduct)
                LargestPalindromicProduct = currentFirstProduct * currentSecondProduct;
        }
    }
    return LargestPalindromicProduct;
}