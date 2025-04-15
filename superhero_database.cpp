#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

const int HERO_COUNT = 10;

string names[HERO_COUNT] = {
    "Bouncing Boy", "El Guapo", "Gin Genie", "Stardust the Super Wizard",
    "Split-Man", "Hindsight Lad", "Skateman", "Danny the Street", "Ferro Lad", "Leather Boy"
};

string superpowers[HERO_COUNT] = {
    "Inflates into a bouncing sphere", "Sentient flying skateboard", "Creates seismic waves via alcohol", "Wild alien god-like powers",
    "Can split into two beings", "Analyzes past mistakes", "Roller-skating vigilante", "Sentient, teleporting street", "Turns body into iron", "BDSM gear-wearing anti-hero"
};

string weaknesses[HERO_COUNT] = {
    "Can be deflated/stuck", "Skateboard is moody", "Needs alcohol to use powers", "Extremely cruel and unpredictable",
    "Limited strength per half", "Completely useless in real time", "Not super at all", "Can be isolated or paved", "Vulnerable to anti-metal", "Not actually superpowered"
};

int metadata[HERO_COUNT][2] = {
    {1961, 1}, {2001, 0}, {2001,0}, {1939, 2}, {1966, 2},
    {1993, 0}, {1983, 2}, {1990, 1}, {1966, 1}, {1997, 0}
};

string getUniverseName(int code) {
    switch (code) {
        case 0: return "Marvel";
        case 1: return "DC";
        case 2: return "Other";
        default: return "Unknown";
    }
}

string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

void displayAll(bool toUpper = false) {
    cout << "\n-------------------------------------------------------------\n";
    cout << "Name\t\t\t| Power\t\t\t| Weakness\t| Year | Universe\n";
    cout << "-------------------------------------------------------------\n";
    for (int i = 0; i < HERO_COUNT; i++) {
        string name = names[i];
        string power = superpowers[i];
        string weakness = weaknesses[i];

        if (toUpper) {
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            transform(power.begin(), power.end(), power.begin(), ::toupper);
            transform(weakness.begin(), weakness.end(), weakness.begin(), ::toupper);
        } else {
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            transform(power.begin(), power.end(), power.begin(), ::tolower);
            transform(weakness.begin(), weakness.end(), weakness.begin(), ::tolower);
        }

        cout << name << "\t| " << power << "\t| " << weakness
             << "\t| " << metadata[i][0] << " | " << getUniverseName(metadata[i][1]) << endl;
    }
    cout << "-------------------------------------------------------------\n";
}

void searchByName(string keyword) {
    keyword = toLowerCase(keyword);
    bool found = false;

    for (int i = 0; i < HERO_COUNT; i++) {
        if (toLowerCase(names[i]).find(keyword) != string::npos) {
            cout << "\nFound: " << names[i] << " | " << superpowers[i] << " | " << weaknesses[i]
                 << " | " << metadata[i][0] << " | " << getUniverseName(metadata[i][1]) << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No superhero found with name containing: " << keyword << endl;
    }
}

void filterByPower(string keyword) {
    keyword = toLowerCase(keyword);
    bool found = false;

    for (int i = 0; i < HERO_COUNT; i++) {
        if (toLowerCase(superpowers[i]).find(keyword) != string::npos) {
            cout << names[i] << " | Power: " << superpowers[i] << " | Year: " << metadata[i][0]
                 << " | Universe: " << getUniverseName(metadata[i][1]) << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No superheroes found with this power: " << keyword << endl;
    }
}

void sortAlphabetically() {
    for (int i = 0; i < HERO_COUNT - 1; i++) {
        for (int j = 0; j < HERO_COUNT - i - 1; j++) {
            if (names[j] > names[j + 1]) {
                swap(names[j], names[j + 1]);
                swap(superpowers[j], superpowers[j + 1]);
                swap(weaknesses[j], weaknesses[j + 1]);
                swap(metadata[j][0], metadata[j + 1][0]);
                swap(metadata[j][1], metadata[j + 1][1]);
            }
        }
    }
    cout << "Superheroes sorted alphabetically.\n";
}

int main() {
    int choice;
    string input;

    do {
        cout << "\n Superhero Database Menu \n";
        cout << "1. Display All (Uppercase)\n";
        cout << "2. Display All (Lowercase)\n";
        cout << "3. Search by Name\n";
        cout << "4. Search by Superpower\n";
        cout << "5. Sort Alphabetically\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                displayAll(true);
                break;
            case 2:
                displayAll(false);
                break;
            case 3:
                cout << "Enter name keyword: ";
                getline(cin, input);
                searchByName(input);
                break;
            case 4:
                cout << "Enter superpower keyword: ";
                getline(cin, input);
                filterByPower(input);
                break;
            case 5:
                sortAlphabetically();
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}