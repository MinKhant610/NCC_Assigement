#include <iostream>
#define SIZE 100
using namespace std;

int main(){
    string text;
    int move_key = 0;
    char arr[SIZE] = {};

    cout << "Enter text to encrypte : ";
    getline(cin, text);
    cout << "Move Key value :" ;
    cin >> move_key;

    for (int i = 0; i < text.length(); i++){
        char store = text[i];
        arr[i] = store + move_key;
    }

    cout << "\nEncryption text :";

    for (int i = 0; i < text.length(); i++){
        cout << arr[i];
    }

    cout << "\n\nSuccessfully Encrypt" << endl;
    return 0;
}