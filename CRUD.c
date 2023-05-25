#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct books{ // DECLARING THE STRUCTURE TO STORE THE DETAILS ABOUT THE LIBRARY BOOK 
    char title[20];
    char author[20];
    int year;
    int id;
} Book;



Book library[100];
int bookCount=0;



// Declaring the functions for CRUD operations
void createBook();
void displayBooks();
void updateBook();
void deleteBook();




int main() //Main function
{
    int choice;
    while (1){
        printf("\n Library Management System \n");
        printf("1) Add the book of your choice (Create).\n");
        printf("2) Display the book of your choice (Display).\n");
        printf("3) Update the book of your choice (Update).\n");
        printf("4) Delete the book of your choice (Delete).\n");
        printf("5) Exit. Have a great day.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}





void createBook() // CREATION
{
    if (bookCount==100){
        printf("Library is full, unable to add your book.\n");
        return;
    }
    Book newBook;
  
  // Taking the details for the book
  
    printf("Enter the book title: ");
    scanf(" %[^\n]s",newBook.title);
    printf("Enter the author name: ");
    scanf(" %[^\n]s",newBook.author);
    printf("Enter the publication year: ");
    scanf("%d",&newBook.year);
    newBook.id=bookCount+1;
    library[bookCount]=newBook;
    bookCount++;
    printf("Book added successfully.\n");
}






void displayBooks() // DISPLAY
{
    if (bookCount==0) {
        printf("No books available.\n");
        return;
    }
    printf("Books present in the library are:\n");
    for (int i=0;i<bookCount;i++) { //SHOWING ALL THE PRESENT BOOKS IN THE LIBRARY
        printf("ID: %d\n",library[i].id);
        printf("Title: %s\n",library[i].title);
        printf("Author: %s\n",library[i].author);
        printf("Year: %d\n",library[i].year);
        printf("\n");
    }
}





void updateBook() // UPDATE
{
    int bookID,found=0;
    if (bookCount==0) {
        printf("No books available.\n");
        return;
    }

    printf("Enter the ID of the book to be updated: ");
    scanf("%d",&bookID);

    for (int j=0;j<bookCount;j++) { // CHECKING WHETHER THE REQUIRED BOOK ID IS PRESENT IN THE LIBRARY
        if (library[j].id==bookID) {
            printf("Enter the new title: ");
            scanf(" %[^\n]s",library[j].title);
            printf("Enter the new author: ");
            scanf(" %[^\n]s",library[j].author);
            printf("Enter the new publication year: ");
            scanf("%d",&library[j].year);
            found=1;
            break;
        }
    }

    if (found) {
        printf("Book updated successfully.\n");
    } 
    else{
        printf("Book with ID %d not found.\n", bookID);
    }
}





void deleteBook() // DELETE
{
    int bookID,found=0;
    if (bookCount==0){
        printf("No books available.\n");
        return;
    }
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &bookID);
    for (int k=0;k<bookCount;k++) { // CHECKING WHETHER THE REQUIRED BOOK ID IS PRESENT IN THE LIBRARY
        if (library[k].id==bookID){
            found=1;
          
            // REARRANGING THE INDICES OF THE BOOKS
          
            for (int l=k;l<bookCount-1;l++) {
                library[l] =library[l+1];
            }
            bookCount--;
            break;
        }
    }
    if (found) {
        printf("Book deleted successfully.\n");
    } 
    else {
        printf("Book with ID %d not found.\n", bookID);
    }
}




// THE ABOVE PROGRAM CREATES A LIBRARY MANAGEMENT SYSTEM WITH ALL THE NECESSARY OPERATIONS 
