#include <iostream>
// Including the standard C++ library allows for the use of string operations such as sort.
#include<bits/stdc++.h>

using namespace std;

bool isPerm(string str1, string str2) {
    // Return false if they're different lengths because we know they can't be permutations.
    if(str1.length() != str2.length()) {
        return false;
    }
    // This sorts the strings and then compares them to see if they're equal
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    if(str1 == str2) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    // Inside main, the user is prompted for 2 strings to be compared.
    string str1, str2, runAgain = "y";
    // Do While loop allows user to compare as many strings as they'd like.
    do {
        
        cout << "Please enter your first string: ";
        cin >> str1;
        cout << "Please enter your second string: ";
        cin >> str2;
    
        // isPerm check
        if(isPerm(str1, str2)) {
            cout << "These strings are permutations.";
        } else {
            cout << "These strings are not permutations of each other.";
        }
        
        cout << "\n\nWould you like to run again? (y = yes, n = no)";
        cin >> runAgain;
        cout << "\n";
    } while(runAgain == "y");

    return 0;
}
