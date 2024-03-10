
/*
FCAI-CS112-Structured programming-2024-assignment 2

program describtion: this program consists of 3 cipher programs (simple substitution cipher,morse cipher,vignere cipher), the main menu appears to the user to choose
one of the cipher programs or to exit the whole program.

Date: 10/3/2024

version: 1.0

Author1: Basel Mohamed Abdelmoneim Mohamed Holaiel , id: 20230085 (simple substitution cipher)

Author2: Mohamed Ahmed Mohamed Mostafa Elkady , id: 20230317 (morse cipher)

Author3: Marwan Khaled Sayed Boraey , id: 20230383 (vignere cipher)

section: s22





*/



#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <string>
#include <limits>
using namespace std;
int main(); // pre declaring the main function.

bool check_repeated_chars(string checker){ // checking if the key contains repeated chars

    int counter = 0;
    for(int k = 0; k < 5 ; k++) {
        for (int j = 0; j < 5 ; j++) {
            if (k == j)continue;
            if (checker[k] == checker[j]){++counter;}
            if(counter == 1){ // if there is at least two repeated chars the function returns false
                return false;
            }
        }
    }



    return true; // if the function didnt return false and dont have repeated chars it returns true
}

bool check_choose(string choice){ // checking the validity of the input of the main menu
   for(int i=0 ; i<choice.length() ; i++){
       if(!isdigit(choice[i])) {return false;} // if the input is not digit return false
       else if((stoi(choice)<1 || stoi(choice)>3)){ // if the input is not from 1 to 3 return false
           return false;
       }

   }
   return true; // otherwise return true if the input is valid

}

bool check_key(string checker){ // checking the validity of the key and calling check_repeated_chars function

    for(int i =0; i<checker.length() ;i++){
        if(!isalpha(checker[i]) || checker.length()!=5 || !check_repeated_chars(checker)){
            return false; 
        } // if the key doesnt contains alphabets or its length not equal 5 or have repeated chars return false
    }
    return true; // otherwise return true
}

int menu(){ // this is the interface of the program that takes the desired choice from the user
    while (true){
cout << "\n################ Welcome to simple substitution cipher ####################\n";
    cout << "1) Encrypt a message\n2) Decrypt a message\n3) Exit the program\n";
    cout << "please enter the number of your desired choice: ";
    string choose;
    cin >> choose;
    while(!check_choose(choose)){ // checking validity of the input by calling check_choose function
        cout << "error enter a number between 1 and 3: ";
        cin >> choose;
    }
    return stoi(choose); // this function returns the valid choice from 1 to 3
    }
    


}


void decrypted_sentence(vector <char> plain_alphabets,vector <char> cipher_alphabets){ // decryption function
    string cyphered_text;
    string decrypted_sent;
    decrypted_sent = "";
    cout << "enter a text to decrypt it: ";
    cin.ignore();
    getline(cin,cyphered_text); // inputting the text which will be decrypted

    for(int i = 0; i<cyphered_text.length() ;i++){
        if(isalpha(cyphered_text[i])){ // if the char in the text is alphabet append the corresponding char to it in plain_alphabets to the decrypted_sent string
            for(int j=0 ; j<26 ; j++){
                if(tolower(cyphered_text[i]) == tolower(cipher_alphabets[j]) ){
                    decrypted_sent+= tolower(plain_alphabets[j]);
                    break;
                }
            }
        }
        else{
            decrypted_sent+=cyphered_text[i]; // if the char is not alphabet add it to decrypted_sent string 
        }
        

    }

    cout << "the decrypted sentence is: "<< decrypted_sent << endl; // display the decrypted_sent to the user
}

void encrypted_sentence(vector <char> plain_alphabets,vector <char> cipher_alphabets){ // encryption function

    string plain_text;
    string encrypted_sent;
    encrypted_sent = "";
    cout << "enter a text to encrypt it: ";
    cin.ignore();
    getline(cin,plain_text); // inputting the text to be encrypted from the user

    for(int i = 0; i<plain_text.length() ;i++){ 
        if(isalpha(plain_text[i])){ // if the char in the text is alphabet append the corresponding char to it in cipher_alphabets to the encrypted_sent string
            for(int j=0 ; j<26 ; j++){
                if(tolower(plain_text[i]) == tolower(plain_alphabets[j]) ){
                    encrypted_sent+= tolower(cipher_alphabets[j]);
                    break;
                }
            }

        }

        else{
            encrypted_sent+=plain_text[i]; // if the char not alphabet append it to the encrypted_sent string
        }

    }

    cout << "the encrypted sentence is: " <<encrypted_sent << endl;
}

void plain_cipher_alphabets(){ // this function declares 2 vectors one for plain alphabets and the other for the cipherd alphabets after inputtingt the key
int num = menu(); // calling menu function and return the choice
if (num==3) { // if the choice is 3 exit the program
    cout << "Exiting the program....\n\n";
    main();
}

bool flag = true; 
string keyword;
cout << "please enter a 5 word keyword: ";
cin >> keyword;
 // inputting the 5 length keyword
while(!check_key(keyword)){ // calling check_key function to check the validity of the input
    cout << "error enter a 5 length key that have different alphabets only: ";
    cin >> keyword;
    // reinputting the key if its not valid
}

int mn = 500; // random big number just to calculate the min char in the key knowing that the biggest value is z = 122
vector <char> plain_alphabets; // declare vector for plain alphabets and clearing it after every loop
plain_alphabets.clear();
vector <char> cipher_alphabets; // declare vector conyain cyphers alphabets after entering the key and clearing it after every loop
cipher_alphabets.clear();


for(int i = 97; i<=122 ; i++){
plain_alphabets.push_back(char(i)); // appending plain alphabets to the first vector
}

for(int i = 0 ;i<keyword.length(); i++){
cipher_alphabets.push_back(tolower(keyword[i])); // appending the 5 length key to the cipher_alphabets vector
mn = min(mn,int(tolower(keyword[i]))); // computing the min char in the key to know the next written char in the key 
}

for(int i = mn+1 ;i<=122; i++){ // starting from the next char after the min char

for(int j = 0 ;j<keyword.length(); j++){
 if(char(i) == tolower(keyword[j])){ // if we found that the next char is in the key then we break the loop to not append it to the ciphers vector
    flag = true;
    break;
 }
 else{
   flag = false;
 }
}

if(!flag) cipher_alphabets.push_back(char(i)); // if the flag is false then append the char to the vector
flag = true; // returning the flag to true to remake the same thing on all chars

}
if(num==1){ // if the choice is 1 then call the encrypted_sentence functiom
     encrypted_sentence(plain_alphabets,cipher_alphabets);
}
else if(num==2){ // if the choice is 2 then call the decrypted_sentence functiom
    decrypted_sentence(plain_alphabets,cipher_alphabets);
}

}

// simple substitution cipher
int main1() {


while(true){ // infinite loop until user choose to exit the program

    plain_cipher_alphabets(); // calling the plain_cipher_alphabets function
}
    return 0;
}


// vigenere cipher problem 
int main2() {
    int choice;
    cout << "################## Welcome to Vigenere Cipher Program ##################\n"; // Display welcome message
    while (true) {
        cout << "Enter a choice between these choices:\n1)Encryption\n2)Decryption\n3)Exit\n";
        if (!(cin >> choice)) { // Check if input is valid
            cout << "Invalid input. Please try again.\n";
            cin.clear(); // Clear error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            continue;
        }
        if (choice == 1) { // Encryption
            string keyword, message, encrypt;
            cout << "Enter an original message: \n";
            cin.ignore(); // Ignore remaining newline characters
            getline(cin, message); // Get message
            cout << "Enter a repeated keyword: \n";
            getline(cin, keyword); // Get keyword
            for (int i = 0; i < message.length(); ++i) { // Repeat through each character in the original message
                if (!isalpha(message[i])) { // Check if character is alphabetic
                    encrypt += message[i]; // If not alphabetic, append character as it is
                    continue;
                }
                // Encrypt alphabetic characters using Vigenere Cipher
                encrypt += (((toupper(message[i]) - 'A') + (toupper(keyword[i % keyword.length()]) - 'A')) % 26) + 'A';
            }
            cout << "Encrypted message: " << encrypt << endl; // Display encrypted message
        }
        else if (choice == 2) { // Decryption
            string keyword, message, encrypt;
            cout << "Enter an encrypted message: \n";
            cin.ignore(); // Ignore remaining newline characters
            getline(cin, encrypt); // Get encrypt
            cout << "Enter a repeated keyword: \n";
            getline(cin, keyword); // Get keyword
            for (int i = 0; i < encrypt.length(); ++i) { // Repeat through each character in the encrypted message
                if (!isalpha(encrypt[i])) { // Check if character is alphabetic
                    message += encrypt[i]; // If not alphabetic, append character as it is
                    continue;
                }
                // Decrypt alphabetic characters using Vigenere Cipher
                message += (((toupper(encrypt[i]) - 'A') - (toupper(keyword[i % keyword.length()]) - 'A') + 26) % 26) + 'A';
            }
            cout << "Decrypted message: " << message << endl; // Display decrypted message
        }
        else if (choice == 3) { // Exit
            cout << "Exiting program.\n";
            cout << "Thanks for using my program\n";
            main();
        }
        else { // Invalid choice
            cout << "Invalid choice. Please try again.\n";
            continue;
        }
    }
}

// morse code cipher
string eng_to_morse (string text, string morse[26]);
string morse_to_eng (string morsecode, string morse[26],char alpha[26]);

string check_morse(string checker){

    for(int i =0 ;i<checker.length();i++){
        if(checker[i]!='.' && checker[i]!='-' && !isspace(checker[i])){
            cout << "Error please enter an right morse code (.,-): ";
            getline(cin,checker);
            i=0;

        }
    }
    return checker;
}

string check_validity_txt(string checker){

    for(int i =0 ;i<checker.length();i++){
        if(!isalpha(checker[i]) && !isspace(checker[i])){
            cout << "Error please enter an input that doesn't include numbers or special characters: ";
            getline(cin,checker);
            i=0;

        }
    }
    return checker;
}

void main3() {
    string morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                        "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                      'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    
    string text, morsecode;
    string choice;

    while (true){
        cout<< "################### Welcome to morse code cipher ##############################\n";
        cout << "Choose a number from 1, 2, or 3: " << endl;
        cout << "1) Decode English to Morse code\n2) Encode Morse code to English\n3) Exit the program" << endl;
        cin >> choice;

        if (choice == "1") {
            cout << "Enter a text to translate, each word separated by a space: ";
            cin.ignore();
            getline(cin, text);
             eng_to_morse(text, morse);
        } else if (choice == "2") {
            cout << "Enter a valid Morse code to translate"<< endl;
            cout<< "each letter code separated by a space" <<endl;
            cout <<  "If you want to translate more than one word, have 3 spaces between each word: ";
            cin.ignore();
            getline(cin, morsecode);

             morse_to_eng(morsecode,morse,alpha);
        } else if (choice == "3") {
          cout << "Exiting the program...\n\n";
            break;
        }
        else {
            cout << "please enter a valid choice from 1,2 and 3: " <<endl;
            
        }
    }
    main();
}

string eng_to_morse(string text, string morse[26]) {
    string morsevalue="";
    string spacesbtwletters = " ";
    string spacesbtwwords = "  ";
    text  = check_validity_txt(text);

    for (int i = 0; i<text.length(); i++) {
        if (text[i] != ' ') //if the word did not encounter a space
        {
            text[i] = toupper(text[i]);
            morsevalue += (morse[text[i] - 'A'] + spacesbtwletters);
        }
        if (text[i] == ' ') {
            morsevalue += spacesbtwwords;//adds 3 spaces when there is a space between words
        }
    }
    cout << "MORSE: " << morsevalue << endl;
    return morsevalue;
}

string morse_to_eng(string morsecode, string morse[26],char alpha[26]) {
morsecode = check_morse(morsecode);
int index = 0;
string output = "",temp="";  
while(index<morsecode.length()){

  if(index==morsecode.length()-1){
    temp+=morsecode[index];
    for(int i =0;i<26;i++){
    if(temp==morse[i]){
      output+=alpha[i];
    }
  }
  cout << "TEXT: " << output << endl;
  return output;

  }
if(!isspace(morsecode[index])){
  temp+=morsecode[index];
  
  
}
else if(isspace(morsecode[index])&& temp.length()!=0){
  for(int i =0;i<26;i++){
    if(temp==morse[i]){
      output+=alpha[i];
    }
  }
  temp="";
  
  

}
 if(isspace(morsecode[index]) && isspace(morsecode[index+1]) && isspace(morsecode[index+2])){
 output+=' ';
 index+=3;
 continue;
 
}
index++;
}
cout << "TEXT: " << output << endl;
return output;
    
}

// main function of the 3 programs
int main(){
string input;
cout << "################### Welcome to our program #########################\n";
cout << "1) simple substitution\n2) morse code\n3) vignere cipher\n4) Exit program\n";
cin >> input;
while (true){
if(input== "1"){
main1();
}
else if(input == "3"){
    main2();
}
else if(input == "2"){
main3();
}
else if(input == "4"){
    cout << "Exiting the program...\n\n";
    exit(0);
}
else{
    cout << "error please input a number from 1 to 4: ";
    cin >> input;
}

}
return 0;

} 