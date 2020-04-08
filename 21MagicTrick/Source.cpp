#include <chrono>
#include <deque>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>
#include <random>

using namespace std;

const int CELL_WIDTH = 10;

void collectCols(deque<int>& deck, char col) {
    deque<int> colA;
    deque<int> colB;
    deque<int> colC;

    for (unsigned int i = 0; i < deck.size(); i += 3) {
        colA.push_back(deck.at(i)); // Col B contains indexes starting at 0, then add 3
    }

    for (unsigned int i = 1; i < deck.size(); i += 3) {
        colB.push_back(deck.at(i)); // Col B contains indexes starting at 1
    }

    for (unsigned int i = 2; i < deck.size(); i += 3) {
        colC.push_back(deck.at(i)); // Col B contains indexes starting at 2
    }

    deck.clear();

    if (col == 'a') {
        // Place col A inbetween B & C

        for (unsigned int i = 0; i < colC.size(); i++) {
            deck.push_back(colC.at(i));
        }

        for (unsigned int i = 0; i < colA.size(); i++) {
            deck.push_back(colA.at(i));
        }

        for (unsigned int i = 0; i < colB.size(); i++) {
            deck.push_back(colB.at(i));
        }
    }
    else if (col == 'b') {
        // Place col B inbetween A & C

        for (unsigned int i = 0; i < colA.size(); i++) {
            deck.push_back(colA.at(i));
        }

        for (unsigned int i = 0; i < colB.size(); i++) {
            deck.push_back(colB.at(i));
        }

        for (unsigned int i = 0; i < colC.size(); i++) {
            deck.push_back(colC.at(i));
        }
    }
    else if (col == 'c') {
        // Place col C inbetween B & A

        for (unsigned int i = 0; i < colA.size(); i++) {
            deck.push_back(colA.at(i));
        }

        for (unsigned int i = 0; i < colC.size(); i++) {
            deck.push_back(colC.at(i));
        }

        for (unsigned int i = 0; i < colB.size(); i++) {
            deck.push_back(colB.at(i));
        }
    }    
}

// Output deque in a nice grid
void print(deque<int> deck) {
    int totalCols = 3;
    int totalRows = 7;

    cout << right << setw(CELL_WIDTH) << "Column A" << setw(CELL_WIDTH) << "Column B" << setw(CELL_WIDTH) << "Column C" << endl;

    unsigned int i = 0;
    for (int r = 0; r < totalRows; r++) {
        for (int c = 0; c < totalCols; c++) {
            cout << right << setw(CELL_WIDTH/2) << " " << left << setw(CELL_WIDTH/2) << deck.at(i); // Center each item
            i++;
        }
        cout << endl;
    }
}

// Shuffle a deque
void shuffle(deque<int>& deck) {
    int randomIndex;
    int originalValue;

    // initialize random seed (time -> iomanip)
    srand(time(NULL));

    // generate secret number between 0 and size of deque:
    randomIndex = rand() % deck.size();

    // Swap item with the randomly chosen item
    for (unsigned int i = 0; i < deck.size(); i++) {
        originalValue = deck.at(i);
        deck.at(i) = deck.at(randomIndex);
        deck.at(randomIndex) = originalValue;
        randomIndex = rand() % deck.size();
    }
}

void findCard(deque<int>& deck) {
    char col;

    print(deck);

    cout << "Enter the column of the number (a, b, c): ";
    cin >> col;

    collectCols(deck, col);
    
}

int main() {
	// deque of numbers
    deque<int> cards = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };
    int userCard;

    // shuffle(nums);

    cout << "Welcome to the 21 Magic Trick Program!" << endl << endl;

    print(cards);

    cout << "Pick a number!" << endl << endl;

    for (int i = 0; i < 3; i++) {
        findCard(cards);
        cout << endl;
    }

    userCard = cards.at(10);

    cout << "Now I'm going to collect the cards and create a 4x5 grid and discard the last card (" << cards.back() << ")" << endl << endl;;

    cout << right << setw(CELL_WIDTH) << "Column A" << setw(CELL_WIDTH) << "Column B" << setw(CELL_WIDTH) << "Column C" << setw(CELL_WIDTH) << "Column D" << endl;
    unsigned int i = 0;
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 4; c++) {
            cout << right << setw(CELL_WIDTH/2) << " " << left << setw(CELL_WIDTH/2) << cards.at(i); // Center each item
            i++;
        }
        cout << endl;
    }

    this_thread::sleep_for(chrono::seconds(1));

    cout << "Hmm" << endl;
}