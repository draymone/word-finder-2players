#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

string getMotPourAiderADeviner(string original)
{
    int randomeNumber(0);
    randomeNumber = rand() % original.size();
    char letterToRemove;
    char letterToRemove2;

    letterToRemove = original[randomeNumber];
    original.erase(randomeNumber, 1);

    randomeNumber = rand() % original.size();
    letterToRemove2 = original[randomeNumber];
    original.erase(randomeNumber, 1);

    original = letterToRemove2 + original + letterToRemove;
    return original;
}


int main()
{
    //initialise random
    srand(time(0));

    //variables
    string originalWord;
    string helpWord;
    string givenWord;
    bool toFind;


    //1 we ask for the word
    cout << "Player 1, enter a word" << endl;
    cin >> originalWord;


    for (int i(0); i<30; i++) {
        cout << endl;
    }


    //2 we change the characters order
    helpWord = getMotPourAiderADeviner(originalWord);

    //3 loop where the user try to find the word
    cout << "Player 2, it's your turn" << endl;
    do {
        cout << "Try to find the word, hint: " << helpWord << endl;
        cin >> givenWord;
        if (givenWord ==  originalWord) {
                cout << endl <<"CONGRATS !" << endl << endl;
            toFind = true;
        }else {
            toFind = false;
        }
    }while (!toFind);

    return 0;
}
