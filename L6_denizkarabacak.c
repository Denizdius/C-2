#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6//For limit the list 

const char *c[N] = {"Life of Pi", "Blood Diamond", "Shutter Island", "Django Unchained", "Winter Sleep", "Children of Men"};
const char *d[N] = {"Ang Lee", "Edward Zwick", "Martin Scorsese", "Quentin Tarantino", "Nuri Bilge Ceylan", "Alfonso Cuaron"};

struct Node {
    char movie_name[30];  //character limit
    char movie_director[30];
    struct Node *next;
};

struct Node *Node_head = NULL;

// Function to insert a new node at the front of the linked list
void insert_front(int c_select) {
    struct Node *Node_entry = (struct Node*)malloc(sizeof(struct Node));//memory allocation for new node
    strcpy(Node_entry->movie_name, c[c_select]);//copying the movie name from the array using strcpy function
    strcpy(Node_entry->movie_director, d[c_select]);//same as  movie name
    Node_entry->next = Node_head;
    Node_head = Node_entry;
}

// Function to insert a new node at the rear of the linked list 
//If the list is empty, it sets the head of the list to the new node. 

void insert_rear(int c_select) {
    struct Node *Node_entry = (struct Node*)malloc(sizeof(struct Node));
    strcpy(Node_entry->movie_name, c[c_select]);
    strcpy(Node_entry->movie_director, d[c_select]);
    Node_entry->next = NULL;
    if (Node_head == NULL) {
        Node_head = Node_entry;
        return;
    }
    struct Node *last = Node_head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = Node_entry;
}

// Function to remove a node from the front of the linked list
// If the list is empty, it prints an error message.
void remove_selected(int c_select) {
    struct Node *temp = Node_head, *prev;
    if (temp != NULL && strcmp(temp->movie_name, c[c_select]) == 0) {
        Node_head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && strcmp(temp->movie_name, c[c_select]) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Movie not found in the list.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}



// Function to print the list
void print_cl() {
    struct Node *temp = Node_head;
    printf("Favorite Movie List:\n");
    while (temp != NULL) {
        printf("%s - %s\n", temp->movie_name, temp->movie_director);
        temp = temp->next;
    }
}

// Function to checks if a movie already exists in the linked list. It takes an integer
int movie_check(int c_select) {
    struct Node *temp = Node_head;
    while (temp != NULL) {
        if (strcmp(temp->movie_name, c[c_select]) == 0) {
            printf("Movie already exists in the list.\n");
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

int main() {
    int oSel, cSel;

    while (1) {//loop for operation selection
        printf("\nChoose operation:\n");
        printf("1. Add a movie at the front of the FavoriteList\n");
        printf("2. Add a movie at the end of the FavoriteList\n");
        printf("3. Remove a movie from FavoriteList\n");
        scanf("%d", &oSel);

        switch (oSel) {//switch for operation selection
            case 1:
                printf("Choose a movie to add to the front of the list:\n");
                for (int i = 0; i < N; i++) {//loop for movie selection at front
                    printf("%d. %s - %s\n", i+1, c[i], d[i]);
                }
                scanf("%d", &cSel);
                if (movie_check(cSel-1)) {// Check if the selected movie already exists in the list
                    insert_front(cSel-1); // Insert the selected movie at the front of the list
                    print_cl(); // Print the list
                }
                break;
            case 2:
                printf("Choose a movie to add to the end of the list:\n");
                for (int i = 0; i < N; i++) {//loop for movie selection at end 
                    printf("%d. %s - %s\n", i+1, c[i], d[i]);
                }
                scanf("%d", &cSel);
                if (movie_check(cSel-1)) {//same!
                    insert_rear(cSel-1);
                    print_cl();
                }
                break;
            case 3:
                printf("Choose a movie to remove from the list:\n");
                print_cl();
                for (int i = 0; i < N; i++) {//loop for movie selection to remove
                    printf("%d. %s - %s\n", i+1, c[i], d[i]);
                }
                scanf("%d", &cSel);//same!
                remove_selected(cSel-1);
                print_cl();
                break;
            default:
                printf("Invalid operation.\n");//anytinhg invalid word unless 1,2,3
                break;
        }
    }
    return 0;
}
