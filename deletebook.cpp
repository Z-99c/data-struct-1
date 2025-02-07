#include <stdio.h>
#include <stdlib.h>

typedef struct Book
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next;
} Book;


//
// FUNCTION : deleteBook
// DESCRIPTION :
// This function will delete the book from the linked list and free the memory
// PARAMETERS :
// Book** head:  it will call the first book
// int id: it will check the book that needs to be removed	
// RETURNS :
//  Void
//
void deleteBook(Book** head, int id);


void deleteBook(Book** head, int id)
{	
	// check if the list is empty 
	if (*head == NULL)
	{
		return;
	}

	Book* currentBook = *head; // the pointer will  to the first book
	Book* previousBook = NULL; // this will track the previous book

	// a loop to get across the linked list
	while (currentBook != NULL)
	{	
		// this will check if the book will match the id
		if (currentBook->id == id)
		{
			// if want to remove is the first one in the list
			if (previousBook == NULL)
			{
				*head = currentBook->next; //move the head to the next book so it won't be lost

			}

			// incase the book is somewhere in the linked list
			else
			{
				previousBook->next = currentBook->next; // link the previous book to the next

			}
			free(currentBook); // this will free the memorty of the deleted book
			return;

		}

		previousBook = currentBook; // this will update the previous book 
		currentBook = currentBook->next; // this will move the current book to the next one

	}

}
