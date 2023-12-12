#include<stdio.h>
#include<string.h>
#define maxbooks 100
struct book{
char title[20];
char author[400];
int idbn;
float price;
};
struct book inventory[maxbooks];
int numBooks=0;
//function to add books!!!
void addBook(char title[],char author[],int idbn,float price){
if(numBooks<maxbooks){
    strcpy(inventory[numBooks].title,title);
    strcpy(inventory[numBooks].author,author);
    inventory[numBooks].idbn=idbn;
    inventory[numBooks].price=price;
    numBooks++;
    printf("The book has been added successfully to the inventory\n");

}
else{
    printf("The inventory storage is currently full!");
}
   }
//function to remove book from inventory
void removeBook(int idbn){
int index=-1;

for(int i=0;i<maxbooks;i++)
    {
      if(inventory[i].idbn==idbn){
        index=i;
        break;
      }

    }
if(index!=-1){
    for(int i=index;i<numBooks;i++){
        inventory[i]=inventory[i+1];
    }
    numBooks--;
    printf("The book has been removed successfully!!\n");

               }
else{
    printf("enter a valid idbn number to remove book!!\n");
    }

}
//function to search book by its title
void searchBook(char title[20])
{
int found=0;
for(int i=0;i<numBooks;i++){
   if(strcmp(inventory[i].title,title)==0)
               {
        printf("author:%s\n",inventory[i].author);
        printf("author:%d\n",inventory[i].idbn);
        printf("price:%2f\n",inventory[i].price);
        printf("the book has been searched successfully\n");
        found=1;
        break;
               }
                           }
if(!found){
            printf("enter a valid book name!\n");
        }

}
void displayInventory(){
if(numBooks==0){
    printf("inventory is empty right now");

}
else{
    for(int i=0;i<numBooks;i++){
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", inventory[i].title);
        printf("Author: %s\n", inventory[i].author);
        printf("Price: %.2f\n", inventory[i].price);
        printf("The inventory is displayed!\n");
    }
}
}
int main() {


    addBook("The Great Gatsby", "F. Scott Fitzgerald",9785,12.99);
    addBook("To Kill a Mockingbird", "Harper Lee",9784,9.99);
    displayInventory();

    searchBook("The Great Gatsby");
    searchBook(79878);

    removeBook(9785);
    displayInventory();

    return 0;
}
