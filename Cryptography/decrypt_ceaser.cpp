#include <iostream>
#define SIZE 100
using namespace std;

int main(){
    string get_text;
    int move_key = 0;
    char arr[SIZE] = {};

    cout << "Enter text to decrypt : ";
    getline(cin, get_text);
    cout << "Move Key : " ;
    cin >> move_key;

    for (int i = 0; i < get_text.length(); i++){
        char store = get_text[i];
        arr[i] = store - move_key;
    }
    
    cout << "\nDecryption text :";
    
    for (int i = 0; i < get_text.length(); i++){
        cout << arr[i];
    }
    
    cout << "\n\nSuccessfully Decrypt" << endl;
    return 0;
}