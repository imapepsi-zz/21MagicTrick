#include <deque>
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>

using namespace std;

void collectNums(deque<int>& deck, char col) {
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
    const int CELL_WIDTH = 10;
    int totalCols = 3;
    int totalRows = 7;

    cout << right << setw(CELL_WIDTH) << "Column A" << setw(CELL_WIDTH) << "Column B" << setw(CELL_WIDTH) << "Column 3" << endl;

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



int main() {
	// deque of numbers
    deque<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };


    // shuffle(nums);

    cout << "Welcome to the 21 Magic Trick Program!" << endl << endl;

    print(nums);

    cout << "Pick a number!" << endl;

    char col;
    cout << "Enter the column of the number (a, b, c): ";
    cin >> col;

    collectNums(nums, col);

    print(nums);

}