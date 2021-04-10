#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
int MAXLINESIZE = 2147483640;

struct variable_struct {
    struct node *headint;
    struct node *lastint;   
    struct node *headfloat;
    struct node *lastfloat;
    //everything is a linkedlist of bytes, representable as int.float so 6.19 or whatever, for printing the two are combined so lastint "points" to headfloat  
    //whammo bammo simpliscism
};

struct byte {
   char data; 
};

typedef struct variable_struct variable;

int main(int argc, char **argv){

}

variable *variable_new(){
   variable *a;
   a->headfloat = NULL;
   a->headint = NULL;
   a->lastfloat = NULL;
   a->lastint = NULL;
   return a;
}

variable assign(variable *a, variable *b){
    struct node *currenta = a->head;
    struct node *currentb = b->head;
    bool copy = true;
    
    while(copy){
        
    }
}
variable subtract(){

}

variable canperform(){}//returns 0/1 depending on if the supplied operation will not overflow/underflow the value

//lexer

variable lexer(char **argv){
   //https://stackoverflow.com/questions/16869467/command-line-arguments-reading-a-file/16869485
   struct variable *tokens = variable_new();
   FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */
   char buff[MAXLINESIZE]; /* a buffer to hold what you read in */
    /* read in one line, up to BUFSIZE-1 in length */
    while(fgets(buff, MAXLINESIZE - 1, fp) != NULL) 
    {
        /* buff has one line of the file, do with it what you will... */
        char *token = strtok(buff, ' ');
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         regex_t regex;
         int intreg, hexreg, binreg, floatreg;
         intreg = regcomp(&regex, "^[:digit:*]$", 0);
         floatreg = regcomp(&regex, "^[:digit:*].[:digit:]$", 0);
         hexreg = regcomp(&regex, "^0x[:xdigit:*]$", 0);
         binreg = regcomp(&regex, "^[0-1*]$", 0);
         

         //if is not a multipart token (includes spaces)
         if (token[0] == '"'){

         }
         else if (regexec(&regex, token, 0, NULL, 0))
         {
            /* code */
         }
         else if (regexec(&regex, token, 0, NULL, 0))
         {
            /* code */
         }
         else if (regexec(&regex, token, 0, NULL, 0))
         {
            /* code */
         }
         else if (regexec(&regex, token, 0, NULL, 0))
         {
            /* code */
         }
         else{
            //for all characters in token, add to variable tokens
            for (int i = 0; i < length(token); i++){
               insertAfter(,token[i],);
            }
         }
         //add delimiter byte
        printf ("%s\n", buff); /* ...such as show it on the screen */
    }
    fclose(fp);  /* close the file */ 
}

// linked list definitions


struct node {
   struct byte data; //all data is a pair of signed linked list bytes
   int key;
	
   struct node *next;
   struct node *prev;
};

//this link always point to first Link


//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;
	
   for(current = head; current != NULL; current = current->next){
      length++;
   }
	
   return length;
}

//display the list in from first to last
void displayForward() {

   //start from the beginning
   struct node *ptr = head;
	
   //navigate till the end of the list
   printf("\n[ ");
	
   while(ptr != NULL) {        
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

//display the list from last to first
void displayBackward() {

   //start from the last
   struct node *ptr = last;
	
   //navigate till the start of the list
   printf("\n[ ");
	
   while(ptr != NULL) {    
	
      //print data
      printf("(%d,%d) ",ptr->key,ptr->data);
		
      //move to next item
      ptr = ptr ->prev;
      
   }
	
}

//insert link at the first location
void insertFirst(int key, int data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //update first prev link
      head->prev = link;
   }

   //point it to old first link
   link->next = head;
	
   //point first to new first link
   head = link;
}

//insert link at the last location
void insertLast(int key, char data) {

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;
	
   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {
      //make link a new last link
      last->next = link;     
      
      //mark old last node as prev of new link
      link->prev = last;
   }

   //point last to new last node
   last = link;
}

//delete first item
struct node* deleteFirst() {

   //save reference to first link
   struct node *tempLink = head;
	
   //if only one link
   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }
	
   head = head->next;
   //return the deleted link
   return tempLink;
}

//delete link at the last location

struct node* deleteLast() {
   //save reference to last link
   struct node *tempLink = last;
	
   //if only one link
   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
	
   last = last->prev;
	
   //return the deleted link
   return tempLink;
}

//delete a link with given key

struct node* delete(int key) {

   //start from the first link
   struct node* current = head;
   struct node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
   while(current->key != key) {
      //if it is last node
		
      if(current->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = current;
			
         //move to next link
         current = current->next;             
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      current->prev->next = current->next;
   }    

   if(current == last) {
      //change last to point to prev link
      last = current->prev;
   } else {
      current->next->prev = current->prev;
   }
	
   return current;
}

bool insertAfter(int key, int newKey, int data) {
   //start from the first link
   struct node *current = head; 
	
   //if list is empty
   if(head == NULL) {
      return false;
   }

   //navigate through list
   while(current->key != key) {
	
      //if it is last node
      if(current->next == NULL) {
         return false;
      } else {           
         //move to next link
         current = current->next;
      }
   }
	
   //create a link
   struct node *newLink = (struct node*) malloc(sizeof(struct node));
   newLink->key = newKey;
   newLink->data = data;

   if(current == last) {
      newLink->next = NULL; 
      last = newLink; 
   } else {
      newLink->next = current->next;         
      current->next->prev = newLink;
   }
	
   newLink->prev = current; 
   current->next = newLink; 
   return true; 
}