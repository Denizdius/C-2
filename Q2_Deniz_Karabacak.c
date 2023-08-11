#include <stdio.h>
#include <stdlib.h>
#include <string.h>//using the strcpy 

#define N 10//limitation for students keep things simpler

typedef struct Node_std {
    int L_id;
    char L_Name[N];//actcually it is not wise the limit surname and name 
    //such a  number of 10 but I cheked the names and surnames it is okey to use 
    char L_Surname[N];
    struct Node_std *next;//pointer the next node
} Node_std;


//The function it self 
// take  a pointer to the head of the ll, 
//integer for id
//character for surname and name 
Node_std* insert_and_sort(Node_std *head, int id, char name[], char surname[]) {


    Node_std *new_node = (Node_std*) malloc(sizeof(Node_std));//Allacation of memory for a node ll

    new_node->L_id = id;
    strcpy(new_node->L_Name, name);//hinted in instructions
    strcpy(new_node->L_Surname, surname);

    new_node->next = NULL; // Set the   pointer of the new node to NULL

    if (head == NULL || head->L_id >= new_node->L_id) {//made for inital erros : ll is empty or the
    //student İD of the head node is => to the student id  of the new no

        new_node->next = head;

        head = new_node;
    } else {//Diğer state

        Node_std *current = head;


        while (current->next != NULL && current->next->L_id < new_node->L_id) {// until the next node is not NULL and the s_id
        //of the next node  is less than the s_id of the new node
            current = current->next;
        }

        new_node->next = current->next;

        current->next = new_node;
    }

    return head;
}

void printlist(Node_std *head) {//priting to the LIST

    Node_std *current = head;//a pointer to the head node

    while (current != NULL) {
        printf("%d - %s %s\n", current->L_id, current->L_Name, current->L_Surname);//print everything we need
        current = current->next;//move to next node 
    }
}

int main() {



    int i;
    int id[N];
    char *Name[N];
    char *Surname[N];//given in instructions
    Node_std *headOF = NULL;
    
    id[0] = 220206048, Name[0] = "CELIL", Surname[0] = "ATAS";
    id[1] = 230206037, Name[1] = "HAKAN", Surname[1] = "KARA";
    id[2] = 220206032, Name[2] = "ENES", Surname[2] = "MUTLUER";
    id[3] = 230206002, Name[3] = "NIHAL", Surname[3] = "PARLAK";
    id[4] = 240206010, Name[4] = "ZUBEYDE", Surname[4] = "ULUOZ";
    id[5] = 220206012, Name[5] = "MEHMET", Surname[5] = "OKKA";
    id[6] = 230206056, Name[6] = "CEMIL", Surname[6] = "DEMIR";
    id[7] = 230206011, Name[7] = "ELIF", Surname[7] = "GENCER";
    id[8] = 240206011, Name[8] = "MEHMET", Surname[8] = "KOTTAS";
    id[9] = 240206001, Name[9] = "ZELIHA", Surname[9] = "ULUOZ";


    for (i = 0; i < N; i++) {
        headOF = insert_and_sort(headOF, id[i], Name[i], Surname[i]);//simple loop to callling the function for the sorting 
    }

    printlist(headOF);//calling printlist function

    return 0;
}
