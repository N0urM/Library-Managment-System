#include "linkedListClass.h"

void adminMode();
void addStudentRecord();
void editStudentRecord();
void deleteStudentRecord();
//void addBook();
void cancelBook();
void reserveBook();
void printUsers();
void printReservationList();
void printAvaliableBooks();

typedef struct studentData Student;
typedef struct books Book;
typedef struct mynode bookNode;


struct books{
		u32 id;
    char* name;
		bool status; // reserved 0 , available 1
    u8 studentID;
};
Book booklist[10] = {
                    { 0 , "Fantastic beasts" , 0 , 0}, 
                    { 1 , "The alchemist" , 0 ,  0},
                    { 2 , "The idiot brian" , 0, 0},
                    { 3 , "Malala" , 0, 0},
                    { 4 , "Becoming" , 0, 0},
                    { 5 , "Brilliant minds" , 0, 0},
                    { 6 , "Communication skills" , 0, 0},
                    { 7 , "The hunger games" , 0, 0},
                    { 8 , "Harry potter" , 0, 0},
                    { 9 , "Contact" , 0, 0}
                    };

studentNode*  Shead=NULL;
studentNode*  Stail=NULL;
bookNode* Bhead = NULL;
bookNode* Btail = NULL;



void adminMode(){
a:
  printf("\tEnter an option: \n\t1.Add student record\n\t2.Edit student record");
  printf("\n\t3.Reserve a book\n\t4.Cancel reservation\n\t5.Delete user\n\t6.Exit admin mode\n\t");
  u8 choice;
  scanf("%d" , &choice);
  switch (choice)
  {
  case 1:
    addStudentRecord();
    break;
  case 2:
    editStudentRecord();
    break;
  case 3:
    reserveBook();
    break;
  case 4:
    cancelBook();
    break;
  case 5:
    deleteStudentRecord();
    break;
  case 6:
    return;
  default:
    printf("\tinvalid option\n");
    break;
  } 
  goto a;
}

void addStudentRecord (){
   printf("Enter student ID: ");
    u32 id;
    scanf("%d" , &id);
    if(FindNode(Shead , id)){
      printf("ID already exists\n");
      return;
    }
    if(id==0){
      printf("ID can't be zero\n");
      return;
    }
    printf("Enter student name: ");
    char Name[20];
    scanf("%s" , Name);
    printf("Enter student gender: ");
    char gender[10];
    scanf("%s"  , gender);
    printf("Enter student age: ");
    u32 age;
    scanf("%d" , &age);
    studentNode* newStudent =(studentNode*) malloc (sizeof(studentNode));
    strcpy (newStudent->name , Name);
    newStudent->id = id;
    strcpy (newStudent->gender , gender);
    newStudent->age = age;
    newStudent->ptr = Stail;
    appendNode(&Shead , &Stail ,  newStudent);
    if(Shead != NULL && Stail!= NULL)
    printf("Data added succefully\n");
    		printNodes(Shead);

}
void editStudentRecord(){
 
  u32 sid , id , x;
  char name[20] ;
  char gender[10];
  u32 age;
 
  // Create new node to fill new data
  studentNode* newStudent =(studentNode*) malloc (sizeof(studentNode));
  // add initial values to check if new data is entered
  newStudent->age=0;
  strcpy(newStudent->gender , "");
  newStudent->id=0;
  strcpy(newStudent->name , "");
a:
  printf("Enter student ID: ");
  scanf("%d" , &sid);
  printf("Select a properity to edit:\n\n");
  printf("1.name\n2.id\n3.age\n4.gender");
  scanf("%d" , &x);
  

  switch (x)
  {
  case 1:
    printf("Enter new name: ");
    scanf("%s" , name);
    strcpy(newStudent->name , name);
    break;
  case 2:
    printf("Enter new ID: ");
    scanf("%d", &id);
    newStudent->id = id;
    break;
  case 3:
    printf("Enter new Age: ");
    scanf("%d" , &age);
    newStudent->age = age;
    break;
  case 4:
    printf("Enter new gender: ");
    scanf("%s" , gender);
    strcpy (newStudent->gender, gender);
    break;
  default:
    printf("Invalid choice.\n");
    goto a;
    break;
  }
  editNode(Shead , sid, newStudent);
  printf("Data modified succefully..\n");
}

void deleteStudentRecord(){
  printf("Select user ID to delete record: ");
  u8 id;
  scanf("%d" , &id);
  if(!FindNode(Shead , id))
  {
    printf("Record not found\n");
    return;
  }
   int i;
    for(i=0 ; i< 10 ; i++){
      if(booklist[i].status == 1 && booklist[i].studentID == id){
        printf("User has reserved book, Cancel reservation to delete.");
        return;
      }
    }
  deleteNode(&Shead, &Stail , id);
  printf("Record deleted\n");
  printNodes(Shead);
}


/*void addBook(){
  printf("Enter book ID: ");
  u32 id ;
  scanf("%d" , &id);
  printf("Enter book name: ");
  char* name;
  scanf ("%s" , &name);
  Book* newBook = (Book*) malloc(sizeof(Book));
  newBook->id = id;
  newBook->status = 0;
  newBook->name = name;
  appendNode(&Bhead , &Btail , newBook);

}
*/
void reserveBook(){
   
    printAvaliableBooks();
    
    u8 id = 0;
    while(1){

      printf("Select student ID to Reserve: ");
      u8 studentid ;
      scanf("%d" , &studentid);
      printf("Select book id or 10 to exit: ");
      scanf("%d" , &id);
      if(id == 10)
        break;
      if (FindNode(Shead , studentid))
      {
        if ( booklist[id].status == 0){
          booklist[id].status = 1;
          booklist[id].studentID = studentid;
          printf("Book is available, reservation complete\n");

        }
        else {
          printf("Book is not available ");
        }
      }
      else {
        printf("ID not available.\n");
      }
  }

}

void cancelBook(){
  printf("Reserved books list:\n");
  printReservationList();
    a:
    printf("\nSelect a book id to cancel reservation or 10 to Exit: ");
    u8 id ;
    scanf("%d" , &id);
    if(id == 10) 
        return;
    if (id > 9)
    {
      printf("invalid id, try again.\n");
      goto a;    
    }
    if (booklist[id].status == 1 ){ // reserved book
      booklist[id].status = 0;
      booklist[id].studentID = 0;  // no student can have id 0
      printf("Book is now available.\n");
    }else {
      printf("book is not reserved.\n");
    }
}
void printUsers(){
  printNodes(Shead);
}
void printAvaliableBooks(){
  int i;
    for(i=0 ; i< 10 ; i++){
      if(booklist[i].status == 0){
          printf("Book ID: %5d\t Book name: %s\n" , booklist[i].id , booklist[i].name);
      }
    }
}
void printReservationList(){
   int i;
    for(i=0 ; i< 10 ; i++){
      if(booklist[i].status == 1){
          printf("Book ID: %5d\t Book name: %s\tStudentID: %d\n" , booklist[i].id , booklist[i].name , booklist[i].studentID);
      }
    }
}

