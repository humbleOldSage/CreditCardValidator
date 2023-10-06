#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccNumber;
    
    cout << "This program uses the Luhn Algorigthm to validate a CC number." << endl;
    cout << "Type 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a CC number to validate: ";
        cin >> ccNumber;
        
        if (ccNumber == "exit")
            break;
        
        else if (!isNumberString(ccNumber)) {
            cout << "Bad input! ";
            continue;
        }
                    
        int len = ccNumber.length();
        int doubleEvenSum = 0;        
    //Begin from the rightmost digit and double every other digit.
   // If doubling produces a number with two digits, sum those two digits to get a single-digit result.
    //Add up all the single-digit results from the previous step to get the 'doubleEvenSum'.         
        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = ((ccNumber[i] - 48) * 2);
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }        
        // Step 2 : Starting from the rightmost digit, sum up every alternate digit and then add this sum to the 'doubleEvenSum'.        
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (ccNumber[i] - 48);
        }        
//Determine if the final 'doubleEvenSum' value is divisible by 10. If it is, then the CC number is valid; otherwise, it's not.     
        cout << (doubleEvenSum % 10 == 0 ? "Valid!" : "Invalid!") << endl;        
        continue;        
    }

    return 0;
}
