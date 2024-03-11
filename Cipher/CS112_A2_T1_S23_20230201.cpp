//File: CS112_A2_T1_S23_20230201
//Author: Abdelrahman Ahmed Abdlebaky & S23
// Abdelrahman Ahmed
//11410120230201@stud.cu.edu.eg
//ID: 20230201

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string remove_special_chr(string s);
void encryption(string crypto);
void decryption(string decrypt);

int main(){
    bool x = true;

    while(x){
        int choice;
        cout << "=========== Welcome to rout cipher proogram =============" << endl;
        cout << "1: Encrypt message" << endl;
        cout << "2: Decrypt message" << endl;
        cout << "3: Exit" << endl;
        cout << "for exiting choose 3: ";
        cin >> choice;

        if(cin.fail()){
        // Clear falier state
            cin.clear();
            // Clear input buffer
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. please enter a choice." << endl;
            continue;
        }

        if(choice == 1){
            cout << "enter the message you want to enecrypt" << endl;
             encryption("");
        }
        else if(choice == 2){
            cout << "Enter the message you want to decrypt " << endl;
            decryption("");
        }
        else if(choice == 3){
            cout << "Exiting !" ;
            break;
        }
        else {
            cout << "invalid choice please try again" << endl;
        }

    }
}















    //remove special charcaters from str
string remove_special_chr( string str){
    string answer ;
    for(auto &chr : str){
        if(isalpha(chr)){
            answer += chr;
        }
    }

    string final_ans;
    // chaning the char of the string to upper case
    for(auto &chr :answer){
        final_ans += toupper(chr);
    }
    return final_ans;
}
    //Encryption function
void encryption(string crypto) {
    string s ;
    //getline to get all str from st[0] to the end of it
    getline(cin >> ws , s) ; // ws is used to remove any input buffer before the str s
    string n = remove_special_chr(s);
    const int len = (n.length() + 3 - 1) / 3 ; // caluclating the number of rows of the array
    const int x = 3;    //fixing the number of coulmns to 3
    char arr[len][x];
    int f = 0;  //Flag = 0 to track the string

    // This for loop is used to fill the 2d array
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < x; ++j) {
            if (f < n.length()) {
                arr[i][j] = n[f++]; //This means to go to string n and get index f then increment it by 1
            }
            else {
                arr[i][j] = 'X';    //Fill the array with X if there is no more characters
            }
        }
    }

    //These for loops is used to read output the str in a spiral way
    for(int i = 0; i < len ; ++i){
        cout << arr[i][2];

    }
    for(int j = x - 2; j >= 0; j--){
        cout << arr[len - 1][j];
    }
    for(int i = len - 2; i >= 0; --i){
        cout << arr[i][0];
    }
    for(int i = 0; i <= len - 2; i++){
        cout << arr[i][1];
    }
    cout << endl;
}
//Decryption function
void decryption(string decrypt){
        string str ;
        cin >> str;
        int x = 3;
        int len =(str.length() + 3 - 1) / 3; // calucalting the number of rows of the arr
        char  arr[len][x];

        int f = 0;
        // From line 134 to line 154 these for loops is used to fill arr in a spiral way
        for(int i = 0; i < len; ++i){   //Fill last colmun top to bot
            arr[i][2] = str[f];
            f++;
        }
        for(int i = 1; i >= 0; --i) // Fill the last row of the array
        {
            arr[len-1][i] = str[f];
            f++;


        }
        for(int i = len - 2; i >= 0; --i){ // Fill first column of the array from bot to top
            arr[i][0] = str[f];
            f++;

        }
        for(int i = 0; i < len - 1; ++i){ //Fill the array at column 2 to  row - 2
            arr[i][1] = str[f];
            f++;
        }


        for(int i = 0; i < len; i++) //Reading the encrypted message
        {
            for(int j = 0; j < x; j++){
                cout << arr[i][j];
            }
        }
        cout << endl;
    }



