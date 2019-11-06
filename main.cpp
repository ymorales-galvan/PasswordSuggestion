#include <iostream>
#include <string>

using namespace std;

//-PROTOTYPES----------------
// (1) add the function prototypes here to match their definitions (below)
string getUserPassword();
bool acceptedLength(string password);
bool acceptedPhrase(string password);
void displayPassword(string password);
int numberOfDigits(string password);

//---------------------------

//-MAIN PROGRAM--------------
int main()
{
    string entry; // keeps track of what the user entered
    bool isGoodLength = false; // whether it is an acceptable length
    bool isGoodWord = false; // whether it is an acceptable word
    int digits = 0;

    do
    {
        // (2) call the getUserPassword function and store its return in entry
       entry = getUserPassword();
           // getUserPassword = (isGoodLength, entry)       
        // (3) call the acceptedLength function w/ the entry argument
        //     and store its return in isGoodLength
        isGoodLength = acceptedLength(entry);
        
        // (4) call the acceptedPhrase function w/ the entry argument
        //     and store its return in isGoodWord
        isGoodWord = acceptedPhrase (entry);
        digits = numberOfDigits(entry); 

    }while( !isGoodLength || !isGoodWord || digits < 2 );

    cout<<"Password ";
    // (5) call the displayPassword function w/ the entry argument
        displayPassword(entry);    
    cout<<" has been set\n";

    return 0;
}
//----------------------------

//-FUNCTION-DEFINITIONS-------

//asks the user for their password and returns what they entered
string getUserPassword()
{
    string entered;
    cout<<"Please enter your password, between 8-20 characters: ";
    getline(cin, entered);
    return entered;
}

// receives a password and verifies whether or not it is between
// 8 and 20 characters long
bool acceptedLength(string password)
{
    int characters = password.length();

    if( characters >=8 && characters <= 20 )
    {
        return true;
    }
    else
    {  
        return false;
    } 
}

// receives a password as a string and returns whether or not it is an
// accepted word (e.g. "password" is not a valid password
bool acceptedPhrase(string password)
{
    bool acceptable;
    if( password == "password" || password == "12345678"
        || password =="123456789" || password == "qwertyuiop")
    {
        acceptable = false;
    }
    else
    {
        acceptable = true;
    } 
    return acceptable;
}

// receives a password and displays it with *'s replacing each character
void displayPassword(string password)
{
    for(int i=0; i<password.length(); i++)
    {
        cout<<"*";
    }
}
//receives password as a string and initializes a counter variable to zero. 
int numberOfDigits(string password)
{
      int numberCounter = 0;
     // char symbol;

        for(int i=0;i<password.length(); i++)
        {
        char symbol = password[i];
        
        if(symbol >= 48 && symbol <= 57)
       {
       numberCounter++;
       }

       }
        return numberCounter; 
}

//----------------------------
