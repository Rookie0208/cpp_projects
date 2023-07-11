#include<iostream>
using std::cout;
using std::cin;
using std::string;

int getDigits(int number) {
    return (number%10) + (number/10 % 10);
}

int sumOfEvenDigit(const string cardNumber) {
    int sum = 0;
    for(int i = cardNumber.size()-2; i>=0; i-=2) {
        sum += getDigits((cardNumber[i] - '0') * 2);
    }
    return sum;
}

int sumOfOddDigit(const string cardNumber) {
    int sum = 0;
    for(int i = cardNumber.size()-1; i>=0; i-=2) {
        sum += cardNumber[i]-'0';
    }
    return sum;
}

int main() {
    string cardNumber;
    int result = 0;

    cout << "Enter a credit card #: ";
    cin >> cardNumber;

    result = sumOfEvenDigit(cardNumber) + sumOfOddDigit(cardNumber);

    if(result % 10 == 0) cout << "It's a valid card number. \n";
    else cout << "It's an invalid number.\n";
}