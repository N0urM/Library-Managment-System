#include <stdio.h>
#include <stdlib.h>
#include "stdTypes.h"
#include "Roles.h"

void adminLogin();
void userLogin();

int main()

{
  printf("\tWelcome to library system\n\t");
  printf("Please select a mode...\n\t1.Admin mode\n\t2.User mode\n\t3.Exit\n\n");

  u8 x  ;
  scanf("%d" ,&x);
  while(x!=3){

    switch (x)
    {
    case 1:
      printf("\tAdmin mode selected\n\n");
      adminLogin();
      break;
    case 2:
      printf("\tUser mode selected\n\n");
      userLogin();
      break;
    case 3:
      return 0;
    default:
      printf("\tinvalid choice\n\n");
    }
    printf("Please select a mode...\n\t1.Admin mode\n\t2.User mode\n\t3.Exit\n");
    scanf(" %s" , &x);

  }
}

void adminLogin(){
  printf("\tEnter your password: ");
  u16 passKey;
  scanf("%d" , &passKey);
  if(passKey == 1234){
    printf("\tLogged in succefully..\n\n");
    adminMode();
  }else {
    printf("Wrong login details.. Exitting\n");
    return;
  }
}

void userLogin(){
 a:
  printf("\tChoose a user option: \n\n");
  printf("\t1.print users' data\n\t2.print avaliable books\n\t3.print reservation list\n\t4.Exit mode\n\t");
  u8 choice;
  scanf("%d" , &choice);
  switch (choice)
  {
  case 1:
    printUsers();
    break;
  case 2:
    printAvaliableBooks();
    break;
  case 3:
    printReservationList();
    break;
  case 4:
    return;
  default:
    printf("invalid choice..\n");
    break;
  }
  goto a;
}
