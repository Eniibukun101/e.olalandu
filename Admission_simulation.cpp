#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//function to check prime num
bool isPrime(int r) {
    return (
        r == 2 || r == 3 || r == 5 || r == 7 || r == 11 || r == 13 ||
        r == 17 || r == 19 || r == 23 || r == 29 || r == 31 || r == 37 ||
        r == 41 || r == 43 || r == 47 || r == 53 || r == 59 || r == 61 ||
        r == 67 || r == 71 || r == 73 || r == 79 || r == 83 || r == 89 ||
        r == 97
    );
}

int main(){
    //variables
    string name;
    int jamb;
    double waec;
    int age;
    bool first_choice;
    bool d_rec;
    int hostel_pref;
    string hostel;
    int h_fee;
    int g_tuition;
    string admit_stat;
    int scholarship;
    int r;
    int granted;
    int total;

    //fixed values
    double b_tuition = 1500000; //base tuition

    //collecting input
    cout << "What is your name?" << endl;
    cin.ignore();               
    getline(cin, name);         

    cout << "What was your jamb score?" << endl;
    cin >> jamb;
    //jamb cant be higher than 400
    if (jamb > 400)
    {
        cout << "Invalid JAMB score." << endl;
        return 0; // stop program
    }

    cout << "What was your WAEC average?" << endl;
    cin >> waec;

    cout << "How old are you?" << endl;
    cin >> age;

    cout << "Was PAU your first choice? If yes, enter 1, if not, enter 0." << endl;
    cin >> first_choice;

    cout << "Do you have any disciplinary record? If yes, enter 1, if no, enter 0." << endl;
    cin >> d_rec;

    //admission decision
    if ((jamb >= 220 && waec >= 60 && first_choice == true) || (jamb >= 200 && waec >= 70))
    {
        if (d_rec == true || age < 15)
        {
            cout << "Sorry, your application has been rejected." << endl;
            hostel = "Not applicable";
            admit_stat = "Rejected";
            total = 0;
            scholarship = 0;
            granted = 0;
            g_tuition = 0;
            h_fee = 0;
            r = 0;
        }
        else
        {
            cout << "Congratulations! You have been admitted!" << endl;
            admit_stat = "Admitted";

            //scholarship
            if (jamb >= 320)
            {
                scholarship = 30;
                b_tuition = b_tuition - (0.3 * b_tuition);
                cout << "Because of your performance in JAMB, you have been granted a 30% scholarship and your tuition fee is now " << b_tuition << endl;
            }
            else if (jamb >= 280)
            {
                scholarship = 20;
                b_tuition = b_tuition - (0.2 * b_tuition);
                cout << "Because of your performance in JAMB, you have been granted a 20% scholarship and your tuition fee is now " << b_tuition << endl;
            }
            else if (jamb >= 240)
            {
                scholarship = 10;
                b_tuition = b_tuition - (0.1 * b_tuition);
                cout << "Because of your performance in JAMB, you have been granted a 10% scholarship and your tuition fee is now " << b_tuition << endl;
            }
            else
            {
                scholarship = 0;
                cout << "Sorry, you are not eligible for a scholarship." << endl;
            }

            // bonus WAEC rule
            if (waec >= 80 && first_choice == true)
            {
                b_tuition = b_tuition - (0.05 * b_tuition);
            }

            cout << "---------------------------------------------------------------" << endl;
            cout << "Hostel Assignment" << endl;
            cout << "Pick from the options below (1-3):" << endl;
            cout << "1. Main hostel   -N180000" << endl;
            cout << "2. Annex hostel  -N120000" << endl;
            cout << "3. Day student   -No fee" << endl;
            cin >> hostel_pref;

            if (hostel_pref == 1)
            {
                hostel = "Main hostel";
                h_fee = 180000;
            }
            else if (hostel_pref == 2)
            {
                hostel = "Annex hostel";
                h_fee = 120000;
            }
            else if (hostel_pref == 3)
            {
                hostel = "Day student";
                h_fee = 0;
            }
            else
            {
                hostel = "Invalid choice";
                h_fee = 0;
            }

            //random merit grant
            srand(time(0));
            r = 1 + rand() % 100;

            g_tuition = b_tuition; 
            if (isPrime(r))
            {
                granted = 50000;
                g_tuition -= 50000;
            }
            else
            {
                granted = 0;
            }

            total = g_tuition + h_fee;
        }
    }
    else
    {
        cout << "Your admission is pending." << endl;
        hostel = "On hold";
        admit_stat = "Pending";
        total = 0;
        scholarship = 0;
        granted = 0;
        g_tuition = 0;
        h_fee = 0;
        r = 0;
    }

    // FINAL OUTPUT
    cout << "---------------------------------------------------------------" << endl;
    cout << "Name: " << name << endl;
    cout << "Admission Status: " << admit_stat << endl;
    cout << "Scholarship: " << scholarship << "% + " << granted << "    Tuition after scholarship= " << g_tuition << endl;
    cout << "Hostel: " << hostel << "   Fee: " << h_fee << endl;
    cout << "Random draw: " << r << "   Merit Grant: " << granted << endl;
    cout << "TOTAL PAYABLE: N" << total << endl;

    return 0;
}
