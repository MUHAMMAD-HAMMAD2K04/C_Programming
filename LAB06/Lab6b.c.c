/* A program shell to maintain a linked list of names */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Maximum length of names */
#define MAXSTRLEN   127

#define STR(EXPR) #EXPR
#define SCANSTR(LEN) "%" STR(LEN) "s"

typedef struct node node_t;

struct node
{
  char data[MAXSTRLEN+1];
  node_t* next;
};

/* Function Prototypes */
void addName (node_t ** firstPtr);
void countList (const node_t * first);
void deleteName (node_t ** firstPtr);
void print (const node_t * first);
void printRec (const node_t * first);
void printLast (const node_t * first);
void printLastRec (const node_t * first);
void printReverse (const node_t * first);
void putFirst (node_t ** firstPtr);

/* Helper function */
void getString (const char * prompt, char * buffer)
{
  int numTokens;
  do {
    printf ("%s", prompt);
    numTokens = scanf (SCANSTR(MAXSTRLEN), buffer);
    if (numTokens==0) {
      printf ("Error reading value. Please try again.\n");
      continue;
    }
  } while (numTokens==0);
}

/* Menu */
void printMenu (void)
{
  printf ("\nOptions available\n");
  printf ("I - Insert a name into the list\n");
  printf ("D - Delete a name from the list\n");
  printf ("C - Count the number of items on the list\n");
  printf ("F - Move an item to the front of the list\n");
  printf ("L - Print the last item (iteratively)\n");
  printf ("M - Print the last item (recursively)\n");
  printf ("P - Print the names (iteratively)\n");
  printf ("S - Print the names (recursively)\n");
  printf ("R - Print the names in reverse order\n");
  printf ("Q - Quit\n");
}

int main (void)
{
  node_t * first = NULL;
  char option [MAXSTRLEN+1];

  printf ("Program to Maintain a List of Names\n");

  while (1) {
      printMenu();
      getString ("Enter desired option: ", option);

      switch (tolower(option[0])) {
        case 'i': addName (&first); break;
        case 'd': deleteName (&first); break;
        case 'c': countList (first); break;
        case 'f': putFirst(&first); break;
        case 'l': printLast(first); break;
        case 'm': printLastRec(first); break;
        case 'p': print(first); break;
        case 's': printRec(first); break;
        case 'r': printReverse(first); break;
        case 'q':
          printf ("Program terminated\n");
          return 0;
        default:
          printf ("Invalid Option - Try Again!\n");
      }
  }
}

/* ADD NAME (already correct) */
void addName (node_t ** firstPtr)
{
  char oldName [MAXSTRLEN+1];
  node_t * newNode = malloc (sizeof (node_t));
  node_t * listPtr;
  node_t * prevPtr;

  if (newNode==NULL) {
    perror ("Unable to allocate node");
    return;
  }

  getString ("Enter name to be inserted into list: ", newNode->data);

  if (*firstPtr == NULL) {
    newNode->next = *firstPtr;
    *firstPtr = newNode;
  }
  else {
    getString ("Enter old name which new name should precede,\n"
               "or enter ? if new name should be placed last: ", oldName);

    if (strncmp (oldName, (*firstPtr)->data, MAXSTRLEN) == 0) {
      newNode->next = *firstPtr;
      *firstPtr = newNode;
    }
    else {
      listPtr = (*firstPtr)->next;
      prevPtr = *firstPtr;

      while (listPtr!=NULL &&
             strncmp (oldName, listPtr->data, MAXSTRLEN) != 0) {
        prevPtr = listPtr;
        listPtr = prevPtr->next;
      }

      newNode->next = prevPtr->next;
      prevPtr->next = newNode;
    }
  }
  printf ("%s inserted into the list\n\n", newNode->data);
}

/* COUNT ITEMS */
void countList (const node_t * first)
{
  int count = 0;
  const node_t * current = first;

  while (current != NULL) {
    count++;
    current = current->next;
  }

  printf ("Total number of items in list: %d\n\n", count);
}

/* DELETE NAME (already correct) */
void deleteName (node_t ** firstPtr)
{
  char name [MAXSTRLEN+1];
  node_t * listPtr;
  node_t * prevPtr;

  if (*firstPtr) {
    getString ("Enter name to be deleted: ", name);

    if (strncmp(name, (*firstPtr)->data, MAXSTRLEN) == 0) {
      listPtr = *firstPtr;
      *firstPtr = (*firstPtr)->next;
      free(listPtr);
      printf("%s removed as first item on list\n\n", name);
    }
    else {
      listPtr = (*firstPtr)->next;
      prevPtr = *firstPtr;

      while (listPtr != NULL &&
             strncmp (name, listPtr->data, MAXSTRLEN) != 0) {
        prevPtr = listPtr;
        listPtr = prevPtr->next;
      }

      if (listPtr != NULL) {
        prevPtr->next = listPtr->next;
        free (listPtr);
        printf ("%s deleted from list\n\n", name);
      }
      else {
        printf ("%s not found on list\n\n", name);
      }
    }
  }
  else {
    printf ("List is empty - no deletions are possible\n");
  }
}

/* ITERATIVE PRINT */
void print (const node_t * first)
{
  printf ("The names on the list are:\n\n");
  for (const node_t * current = first ; current != NULL ; current = current->next)
    printf ("%s\n", current->data);

  printf ("\nEnd of List\n\n");
}

/* RECURSIVE PRINT */
void printRec (const node_t * first)
{
  if (first == NULL) {
    printf ("\nEnd of List\n\n");
    return;
  }
  printf ("%s\n", first->data);
  printRec(first->next);
}

/* PRINT LAST (ITERATIVE) */
void printLast (const node_t * first)
{
  if (first == NULL) {
    printf ("List is empty\n\n");
    return;
  }

  const node_t * current = first;
  while (current->next != NULL) {
    current = current->next;
  }

  printf ("Last item (iterative): %s\n\n", current->data);
}

/* PRINT LAST (RECURSIVE) */
void printLastRec (const node_t * first)
{
  if (first == NULL) {
    printf ("List is empty\n\n");
    return;
  }

  if (first->next == NULL) {
    printf ("Last item (recursive): %s\n\n", first->data);
    return;
  }

  printLastRec(first->next);
}

/* PRINT REVERSE (RECURSIVE) */
void printReverse (const node_t * first)
{
  if (first == NULL)
    return;

  printReverse(first->next);
  printf("%s\n", first->data);
}

/* MOVE A NODE TO FRONT */
void putFirst (node_t ** firstPtr)
{
  if (*firstPtr == NULL) {
    printf ("List is empty\n\n");
    return;
  }

  char name[MAXSTRLEN+1];
  getString ("Enter name to move to front: ", name);

  node_t * current = *firstPtr;
  node_t * prev = NULL;

  /* If already first */
  if (strncmp(current->data, name, MAXSTRLEN) == 0) {
    printf ("Item is already at front\n\n");
    return;
  }

  /* Search the node */
  while (current != NULL &&
         strncmp(current->data, name, MAXSTRLEN) != 0) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    printf ("Name not found in list\n\n");
    return;
  }

  /* Re-link pointers */
  prev->next = current->next;
  current->next = *firstPtr;
  *firstPtr = current;

  printf ("%s moved to front of the list\n\n", name);
}