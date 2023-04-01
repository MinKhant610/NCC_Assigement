/*

mini_bank_project with BST 
admin_account = "MinKhant"
admin_password = 12345 

password are allow only integer;
name are not allow space;

*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
void storeData(ofstream&Name, string name);

struct Node {
    string data ;
    struct Node *left , *right ;
    Node (string data){
        this->data = data;
        left = right = NULL;
    }
};

// just show data
Node* preorder (struct Node *node){
    if (node == NULL){
        return node;
    }
    cout << node->data << "->";
    preorder (node->left);
    preorder(node->right);
}

// input for tree or subtree
Node* user_input(Node* node, string name){
    if (name.size() == node->data.size()){
        name = name + " ";
    }
  if (name.size() < node->data.size()){
    if (node->left == NULL){
      node->left = new Node(name);
    }else {
      user_input(node->left, name);
    }
      
  }else {
    if (node->right == NULL){
      node->right = new Node (name);
    }else {
      user_input(node->right, name);
    }
  }
}

// delete function
Node* delete_node (Node* root, string data){
    if (root == NULL){
        return root;
    }else if (data.size() < root->data.size()){
        root->left = delete_node(root->left, data);
    }else if (data.size() > root->data.size()){
        root->right = delete_node(root->right, data);
    }else {
        if (root->left == NULL && root->right == NULL){
            root = NULL;
        }else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
        }else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
        }else{
            Node* temp = root->right;
            while (temp->left !=NULL){
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }
    return root;
}

//To Read file and search user 
void FileRead(string name){
  ifstream ReadFile("MainDB.txt");
  while(getline(ReadFile, name)){
  cout << name << endl;
  }
}

//Put data in root structure 
void Put_Tree(Node* root){
  string data;
  ifstream Read("MainDB.txt");
  while(getline(Read,data)){
    user_input(root, data);
  }
  
}

// To check number of all username 
int SearchFile_count(string name){
  int count = 0;
  ifstream Read("MainDB.txt");
  while(getline(Read, name)){
    count++;
  }
  return count;
}

//To Search User
void Search(string name){
  int count = 0;
  string search_key;
  cout << "Enter the name to serach :";
  cin >> search_key;
  ifstream ReadFile("MainDB.txt");
  string search_name;
  while(getline(ReadFile, search_name)){
    if (search_key == search_name){
      cout << "\n....User Found.... \n \n";
      return;
    }else {
      cout << "\n..Finding..\n" ;
      count++;
    }
  }
  int all_count = 0;
  all_count = SearchFile_count(name);
  if (count == all_count){
    cout << "User not Found !!! \n \n";
  }
}


//Create Account 
string CreateAccount(Node* root){
  string create_name,create_pass;
  ofstream UserData;

  cout << "Enter your name :";
  cin >> create_name;
  cout << "Enter your pass :";
  cin >> create_pass;
  // Put data in MainDB file
  UserData.open("MainDB.txt",ios::app);
  UserData << create_name << endl;
  UserData.close();

  ofstream CreateName(create_name + ".txt");
  CreateName << create_name + create_pass;
  CreateName.close();

  cout << "\n..Account Create.." << endl;
  cout << "Welocme " << create_name << endl;
  cout << "\n";
}


//Login Account
void LoginAccount (){
  string log_name,log_pass,log_get,log_check;
  cout << "Type your name and pass to login\n" << endl;
  cout << "Enter your name :";
  cin >> log_name;
  cout << "Enter your pass :";
  cin >> log_pass;
  string log_in_check = log_name + log_pass;
  ifstream Read(log_name + ".txt");
  while(getline(Read, log_check)){
    log_get = log_check;
  }
  if (log_in_check == log_check){
    cout << "\n.....Login success.... \n";
    cout << "Welocme " << log_name << "\n" << endl;
  }else {
    cout << "\n......Wrong username or password......\n" << endl;
  }
}

// delete the line from file(MainDB)
void deleteLine(int num){
  int line_number = num;
  ifstream ReadFile("MainDB.txt");
  fstream read_file;

  read_file.open("MainDB.txt");

  vector<string> lines;
  string line;

  while (getline(read_file, line)){
    lines.push_back(line);
  }
  read_file.close();

  ofstream write_file;
  write_file.open("MainDB.txt");
  line_number--;

  for (int i = 0; i < lines.size(); i++){
    if (i != line_number)
    write_file << lines[i] << endl;
  }

  write_file.close();
}

int get_count(string del_name){
  ifstream ReadFile("MainDB.txt");
  string search_name,name;
  int count = 1;
  while(getline(ReadFile, search_name)){
    if (del_name == search_name){
      return count;
    }else {
      count++;
    }
  }
  return 12512;
}

int main () {
    struct Node *root = new Node ("MinKhant"); // admin account
    string admin_account = root->data;
    int admin_pass = 12345;
    int put_count = 0;

    ifstream UserData("MainDB.txt"); //to store data;
    string name;
    int key;
    char usr_name[50];
    string create_name,create_pass;
    int usr_pass;
    
    while (key != 4){
      cout << "Press 1 to Login as admin " << endl;
      cout << "Press 2 to Create account " << endl ;
      cout << "Press 3 to Login in account " << endl;
      cout << "Press 4 to Exit " << endl;
      cout << ">>>> " ;
      cin >> key;

      if (key == 1){
        cout << "Enter name :" ;
        cin >> usr_name;
        cout << "Enter pass :" ;
        cin >> usr_pass;
        if(usr_name == admin_account && usr_pass == admin_pass){
          cout << "\n .....Login success.....\n \n";
          int adm_key = 0; // key which control the admin scope
          while (adm_key != 4){
              cout << "....Choose the option....\n" << endl;
              cout << "Press 1 to Show All User " << endl;
              cout << "Press 2 to Delete Account" << endl;
              cout << "Press 3 to Searh User " << endl;
              cout << "Press 4 to Exit (exit to admin mode) " << endl;
              cout << ">>>> " ;
              cin >> adm_key;

                if (adm_key == 1){
                  cout << "\n.....All user ....\n";
                  FileRead(name);
                  cout << "..................\n \n";

                  cout <<"[ User with Tree Structure ] \n" << endl;
                  if (put_count == 1){
                    preorder(root);
                  }else {
                    Put_Tree(root);
                    preorder(root);
                  }
                  put_count ++;
                  cout << "\n \n [ .........End.........] \n \n";

                }else if (adm_key == 2){
                  string del_name;
                  cout << "Enter the name to delete :" ;
                  cin >> del_name;
                  int line = get_count(del_name);

                  if (line == 12512){
                    cout << "User not found !! " << endl;
                    cout << "Cannot delet !!" << endl;
                  }else {
                    string file = del_name + ".txt";
                    const char* file_name = file.c_str();
                    remove(file_name);
                    delete_node(root,del_name);
                    deleteLine(line);
                    cout << "\n Successfully Delete \n" << endl;
                  }

                }else if (adm_key == 3){
                    Search(name);

                }else if (adm_key == 4){
                  cout << "\n .... Exiting......." << endl;
                  
                }else {
                  cout << "Something Wrong!!! " << endl;
                  exit(1);
                }
            }// complete adm_key step; 

        }else {
        cout << "Worng User name or Password !!!" << endl;
          }
      // start key = 2 
      }else if (key == 2){
      CreateAccount(root);
      //complet key 2 step
      }else if (key == 3){
      LoginAccount();
      //complet key 3 step
      }else if (key == 4){
      cout << "....Exiting......\n";
      }else {
      cout << "Read the step carefully !!!";
      break;
      }

    }

    return 0;
}