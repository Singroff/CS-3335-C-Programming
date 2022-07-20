#include <iostream>
#include <string>

// Global Max Character Variable
#define MAX_CHAR 50

using namespace std;

// Struct Declaration
struct books {
    char name[MAX_CHAR];
    char author[MAX_CHAR];
};

int main()
{
    // Fifty books max
    struct books books[50];
    int numOfBooks = 2;
    
    
    cout << "How many books would you like to enter? (MAX: 50): ";
    cin >> numOfBooks;
    cout << endl;
    
    // cin.ignore() prevents the following for loop from scanning the previous line. I dunno
    // why it works, but it does!
    cin.ignore();
    
    for(int i = 0; i < numOfBooks; i++) {
        
        cout << "Book " << i + 1 << endl;
        
        cout << "Book's Name: ";
        // cin.getline allows for whitespaces
        cin.getline(books[i].name, MAX_CHAR);
        
        cout << "Book's Author: ";
        cin.getline(books[i].author, MAX_CHAR);
        
        cout << endl;
    }
    
    
    cout << endl;
    cout << "Your Bookshelf: " << endl;
    
    // loop that prints all the books the user has entered
    for(int i = 0; i < numOfBooks; i++) {
        cout << "Book " << i + 1 << ": " << books[i].name << " by " << books[i].author;
        cout << endl;
        
    }
    
    

    return 0;
}
