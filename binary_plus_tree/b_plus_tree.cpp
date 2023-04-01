#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

//to append data 
void append(Node **head_ref, int new_data){
    Node *new_node = new Node();
    Node *last = (*head_ref);
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;
}

//for show data in link_list
void dt_print (Node* node) {
	while (node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
}

//for sort data
void insert_sort(vector<int>& arr, int arr_size){
    int first_num,second_num,temp;
    for (first_num = 1; first_num < arr_size; first_num++){
        second_num = first_num;
        while (second_num > 0 && arr[second_num-1] > arr[second_num]){
            temp = arr[second_num];
            arr[second_num] = arr[second_num-1];
            arr[second_num-1] = temp;
            
            second_num--;
        }
    }
}

//for search data
bool search (Node *head_ref, int key){
    Node* current_node = head_ref;
    while(current_node != NULL){
        if(current_node->data == key){
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

//for delete_data 
void delete_data(Node **head_ref, int key){
    Node * prev = NULL;
    Node *temp = *head_ref;
    
    if(temp !=NULL && temp->data == key){
        *head_ref =  temp->next;
        delete temp;
        return;
    }else{
        while(temp !=NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL){
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}

int main(){
    vector<int>num;
    Node* head = NULL;
    head = new Node();
    int count_user_num,data_store;
    int control_loop=0;

    while (control_loop != 99){
        cout << "Choose Option" << endl;
        cout << "press 99 to exit" << endl;
        cout << "press 1 to insert data" <<endl;
        cout << "press 2 to search data" << endl;
        cout << "press 3 to delete data" <<endl;
        cout << "press 4 to show data" << endl;
        cout << "enter option : ";
        cin >> control_loop;

        if (control_loop == 99){
            cout << "exiting..." << endl;

        }else if (control_loop == 1){
            cout << "Enter amount of data : ";
            cin >> count_user_num;   
    
            for (int start_point = 0; start_point < count_user_num; start_point++){
                cout << "Enter data :" ;
                cin >> data_store;
                num.push_back(data_store);
            }
            insert_sort(num, count_user_num);
            for (int i=1; i<count_user_num; i++){
            append(&head,num.at(i));
            }
        }else if (control_loop == 2){
            int search_key;
            cout << "Enter data to search : ";
            cin >> search_key;
            int bool_vale = search(head,search_key);
            if (bool_vale == 1){
                cout << "data found" << endl;
            }else{
                cout << "data not found" << endl;
            }
        }else if (control_loop == 3){
            int delete_key;
            cout << "Enter data to delete : ";
            cin >> delete_key;
            delete_data(&head, delete_key);
            cout << "Delete successfully..." << endl;
        }else if (control_loop == 4){
            dt_print(head);
        }
    }
    return 0;
}