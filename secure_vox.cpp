#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

// Define a structure to store voter information
struct voter_information {
    char reg_no[20]; // Store the registration number
    char name[50];   // Store the name of the voter
    struct voter_information* next; // Pointer to the next voter's information
};

// Alias the structure as 'node'
typedef voter_information node;

// Initialize the head pointer to the linked list as NULL
node* head = NULL;

// Define global variables to keep track of votes and attempts
int R = 3;           // Number of login attempts allowed
int vote1 = 0, vote2 = 0, vote3 = 0, vote4 = 0, vote5 = 0; // Vote counters

// Function prototypes
node* search(char x[], char y[], node* start, int* Y);
node* voter_insert(node*);
void main_logs();
void admin();
void winner();
void exi();
void voting();
void not_again();
void stop();
void show();
void voter_registration(); // New function for voter registration

int main() {
    while (true) {
        system("cls");
        cout << "\n\n\n";
        cout << "\t\t\t*** WELCOME TO THE SECURE VOX VOTING PORTAL ***\n\n";
        cout << "\t\t\t*** Please Enter 1 for logging vote main Logs ***\n\n\n";
        int BB;
        cin >> BB;

        if (BB == 1) {
            main_logs();
        }
    }
    return 0;
}

// Main menu for choosing between voting, admin, checking the winner, or voter registration
void main_logs() {
    cout << "\n\n\n";
    cout << "\t\t\t\t\t1. FOR VOTE ENTRY\n";
    cout << "\t\t\t\t\t2. FOR ADMIN PANEL\n";
    cout << "\t\t\t\t\t3. FOR WINNER\n";
    cout << "\t\t\t\t\t4. FOR VOTER REGISTRATION\n\n"; // Option for voter registration
    cout << "IF YOUR CREDENTIALS MATCHES WITH THOSE IN THE VOTER LIST THEN ONLY YOU CAN GIVE YOUR VOTE OTHERWISE YOU CAN NOT\n\n";
    cout << "**Please Enter your choice**\n\n\n";
    int T;
    cin >> T;

    if (T == 1) {
        voter_insert(head);
    } else if (T == 2) {
        admin();
    } else if (T == 3) {
        winner();
    } else if (T == 4) {
        // Call the voter registration function here
        voter_registration();
    } else {
        main_logs();
    }
}

// Function for registering a voter
node* voter_insert(node* start) {
    // The voter_insert function allows a voter to register and cast their vote.
    int UNIVERSAL = 0; // Flag to check if the voter has already voted
    int* z;
    z = &UNIVERSAL;

    char name[50], reg_no[20];
    system("cls");
    cout << "\n\n\n\n";
    cout << "IF REGISTRATION NUMBER MATCHES THEN YOU CAN GIVE YOUR VOTE OTHERWISE NOT\n\n";
    cout << "ATTEMPTS LEFT: " << R << "\n\n\n";
    cout << "Please enter your\n";
    cout << "\t\tRegistration number: ";
    cin.ignore();
    cin.get(reg_no, 20);
    cout << "\t\tNAME: ";
    cin.ignore();
    cin.get(name, 50);

    int regno = atoi(reg_no);

    if (regno >= 210968000 && regno <= 210968999) {
        R = 3; // Reset login attempts
        start = search(reg_no, name, start, &UNIVERSAL);

        if (UNIVERSAL == 0) {
            voting(); // If not voted before, allow the voter to cast a vote
        } else {
            not_again(); // If the voter has already voted, inform them
        }
    } else {
        R--;
        if (R == 0) {
            stop(); // Lock the user out after three failed attempts
        } else {
            cout << "\n\n\n\n";
            cout << "Your Registration Number isn't valid\n\n";
            cout << "Please Re-Enter\n\n";
            system("pause");
            main_logs();
        }
    }

    return start;
}

// Function for the voting process
void voting() {
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t         * * * * * LIST OF CANDIDATES * * * * *\n\n\n";
    cout << "\t\t\t NAME     & THEIR RESPECTIVE      SYMBOL\n\n";
    cout << "\t\t\t 1. Amarendra Baahubali           (1) Chariot\n";
    cout << "\t\t\t 2. Kattapa                       (2) Sword\n";
    cout << "\t\t\t 3. Bhallaladeva                  (3) Bull\n";
    cout << "\t\t\t 4. Sivagami                      (4) Albatross\n";
    cout << "\t\t\t 5. Devasena                      (5) Swan\n\n\n";

    int B, j;
    cout << "\t\t\t Enter Your Choice\n";
    for (j = 1; j <= 1; j++) {
        cin >> B;

        switch (B) {
            case 1:
                vote1++;
                cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Amarendra Baahubali\n";
                break;
            case 2:
                vote2++;
                cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Kattapa\n";
                break;
            case 3:
                vote3++;
                cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Bhallaladeva\n";
                break;
            case 4:
                vote4++;
                cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Sivagami\n";
                break;
            case 5:
                vote5++;
                cout << "\n\n\t\t\t\tYOU HAVE SUCCESSFULLY GIVEN YOUR VOTE TO Devasena\n";
                break;
            default:
                cout << "\n\t\t***** INVALID CHOICE ENTERED ******\t\t\n";
                cout << "\n\t\t\tENTER AGAIN\t\t\t\n";
                j--; // Prompt for input again
        }
    }
    cout << "\n\n\t\t\t********** THANK YOU *********\n\n";
    cout << "Exiting in 3 seconds";
    Sleep(3000);
    system("cls");
}

// Function for the admin panel
void admin() {
    int B;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\tEnter Your Password To Unlock The Admin Panel\n\n";
    cin >> B;

    if (B == 1234) {
        show(); // If the password is correct, display the voting statistics
    } else {
        cout << "Wrong Password\n";
    }
}

// Function to display the current vote count
void show() {
    int G;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tPresent Vote Count:\n\n";
    cout << "\t\t  Amarendra Baahubali is on " << vote1 << " Votes\n";
    cout << "\t\t  Kattapa is on " << vote2 << " Votes\n";
    cout << "\t\t  Bhallaladeva is on " << vote3 << " Votes\n";
    cout << "\t\t  Sivagami is on " << vote4 << " Votes\n";
    cout << "\t\t  Devasena is on " << vote5 << " Votes\n\n\n\n";
    cout << "\t\t\t\t\tEnter 1 for main logs\n\n\t\t\t\t\t\t\tOR\n\n\t\t\t\t\tENTER THE SPECIAL PASSWORD TO CLOSE THE VOTING PORTAL\n";
    cin >> G;
    if (G == 1234) {
        exi(); // If the special password is entered, exit the program
    } else {
        main_logs();
    }
}

// Function to determine and display the winner
void winner() {
    system("cls");
    cout << "\n\n\n\n";

    if (vote2 < vote1 && vote3 < vote1 && vote4 < vote1 && vote5 < vote1) {
        cout << "\t\tThe present Winner is Amarendra Baahubali and he has got " << vote1 << " votes\n\n\n\n";
    } else if (vote1 < vote2 && vote3 < vote2 && vote4 < vote2 && vote5 < vote2) {
        cout << "\t\tThe present Winner is Kattapa and he has got " << vote2 << " votes\n\n\n\n";
    } else if (vote1 < vote3 && vote2 < vote3 && vote4 < vote3 && vote5 < vote3) {
        cout << "\t\tThe present Winner is Bhallaladeva and he has got " << vote3 << " votes\n\n\n\n";
    } else if (vote1 < vote4 && vote2 < vote4 && vote3 < vote4 && vote5 < vote4) {
        cout << "\t\tThe present Winner is Sivagami and she has got " << vote4 << " votes\n\n\n\n";
    } else if (vote1 < vote5 && vote2 < vote5 && vote3 < vote5 && vote4 < vote5) {
        cout << "\t\tThe present Winner is Devasena and she has got " << vote5 << " votes\n\n\n\n";
    }

    cout << "\t\t\t\tEnter Any Key for Main Logs\n\n";
    cin.ignore();
    cin.get();
    main_logs();
}

// Function to inform the user they have entered wrong credentials multiple times
void stop() {
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\tYOU ENTERED WRONG CREDENTIALS FOR THREE(3) TIMES IN A ROW\n\n\n";
    Sleep(500);
    cout << "\t\t\tPlease try again later\n\n\n";
    Sleep(500);
    cout << "\t\t\t * * * Thank You * * * \n\n\n";
    Sleep(500);
    cout << "Press any key";
    cin.ignore();
    cin.get();
}

// Function to inform the user they have already voted
void not_again() {
    int A;
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t\t\t        *YOU HAVE GIVEN YOUR VOTE SUCCESSFULLY*\n\n\n";
    Sleep(300);
    cout << "\t\t\t        *YOU CANNOT GIVE YOUR VOTE MORE THAN ONCE*\n\n\n";
    Sleep(300);
    cout << "\t\t\t If You want to see the present winner Enter 1 or Enter Any Other Key for Main Logs\n\n";
    Sleep(300);

    cin >> A;

    if (A == 1) {
        winner();
    } else {
        main_logs();
    }
}

// Function to exit the voting portal
void exi() {
    system("cls");
    cout << "\n\n\n\n\n";
    Sleep(500);
    cout << "\t\t\t        *YOU ARE NOW EXITING THE PORTAL*\n\n\n";
    Sleep(1000);
    cout << "\t\t\t * * * Thank You For Using This Platform For VOTING * * * \n\n\n";
    Sleep(1000);
    exit(0);
}

// Function to search for a voter in the linked list
node* search(char x[], char y[], node* start, int* Y) {
    if (Y != NULL)
        *Y = 0;
    node* t;
    t = start;

    while (t != NULL) {
        if (strcmp(t->reg_no, x) == 0 && strcmp(t->name, y) == 0) {
            if (Y != NULL)
                *Y = 1;
            break;
        }
        t = t->next;
    }

    return start;
}

// Function for voter registration
void voter_registration() {
    char name[50], reg_no[20];
    system("cls");
    cout << "\n\n\n\n";
    cout << "ATTEMPTS LEFT: " << R << "\n\n\n";
    cout << "Please enter your\n";
    cout << "\t\tRegistration number: ";
    cin.ignore();
    cin.get(reg_no, 20);
    cout << "\t\tNAME: ";
    cin.ignore();
    cin.get(name, 50);

    int regno = atoi(reg_no);

    if (regno >= 1 && regno <= 210968999) {
        R = 3; // Reset login attempts
        head = search(reg_no, name, head, NULL); // Search if the voter is already registered
        if (head == NULL) {
            node* temp = new voter_information;
            strcpy(temp->reg_no, reg_no);
            strcpy(temp->name, name);
            temp->next = NULL;

            if (head == NULL) {
                head = temp;
            } else {
                temp->next = head;
                head = temp;
            }
            cout << "\n\n\t\t\t********** Registration Successful *********\n";
        } else {
            cout << "\n\n\t\t\t********** You are already registered *********\n";
        }
    } else {
        R--;
        if (R == 0) {
            stop();
        } else {
            cout << "\n\n\n\n";
            cout << "Your Registration Number isn't valid\n\n";
            cout << "Please Re-Enter\n\n";
            system("pause");
            main_logs();
        }
    }
}
