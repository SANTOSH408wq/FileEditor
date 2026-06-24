#include<stdio.h>
void main()
{
char filename[100];
char edit[1024];
int choice;
FILE *file;
clrscr();
printf("C Editor\n");
while(1)
 {
  printf("-----------------------------------------------------------\n");
  printf("1.Create/Open File\n2.Edit File\n3.View File\n4.Exit\n");
  scanf("%d",&choice);
  switch(choice)
   {
    case 1:
    printf("Enter Filename:");
    scanf("%s",&filename);
    file=fopen(filename, "a+");
    if(file==NULL)
     {
      printf("Error opening file.\n");
     }
    else
     {
      fclose(file);
      printf("File opened/created.\n");
     }
    break;
    case 2:
    if(strlen(filename)==0)
     {
      printf("Please open or create a file first.\n");
      break;
     }
    file=fopen(filename, "a");
    if(file == NULL)
     {
      printf("Error opening file.\n");
      break;
     }
    printf("Enter text Ctrl+D or Ctrl+Z on Windows to save):\n");
    while (1)
    {
     if(fgets(edit,sizeof(edit),stdin) == NULL)
      {
       if(feof(stdin))
	{
	 clearerr(stdin);
	 break;
	}
       else
	{
	 break;
	}
      }
      fprintf(file, "%s", edit);
     }
    fclose(file);
    printf("File saved.\n");
    clearerr(stdin);
    break;
    case 3:
    printf("---------------------------------------------------------\n");
    if (strlen(filename) == 0)
     {
      printf("Please open or create a file first.\n");
      break;
     }
    file=fopen(filename, "r");
    if(file==NULL)
     {
      printf("Error opening file.\n");
      break;
     }
    while (fgets(edit, sizeof(edit), file) != NULL)
     {
      printf("%s",edit);
     }
    fclose(file);
    break;
    case 4:
    printf("Press enter to Exit");
    getch();
    return;
    default:
    printf("Invalid choice.\n");
   }
 }
}
