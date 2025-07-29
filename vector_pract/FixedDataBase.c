#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
int cnt=0;
void printMenu(void)
{
	printf("\nName-Database-MENU\n");
	printf("------------------------\n");
	printf("i:input a name\n");
	printf("p:print all names\n");
	printf("q:quit\n");
	printf("f:find a name\n");
	printf("s:sort names\n");
	printf("d:delete by name\n");
	printf("ENter your choice:");
}
void print(char (*ptr)[20]){
    if(cnt==0){
        printf("not names in the databases");
        return ;
    }
    for(int i=0;i<cnt;i++){
        printf("%s\n",ptr[i]);
    }
}

void inputName(char (*ptr)[20]){
    if(cnt==MAX){
        printf("the database is full");
        return ;
    }
    fgets(ptr[cnt],20,stdin);
    ptr[cnt][strlen(ptr[cnt])-1]='\0';
    cnt++;
}
void sort(char (*ptr)[20]){
    char temp[20];
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt-i-1;j++){
            if(strcmp(ptr[j],ptr[j+1])>0){
                strcpy(temp,ptr[j]);
                strcpy(ptr[j],ptr[j+1]);
                strcpy(ptr[j+1],temp);
            }
        }

    }
}
void delete(char (*ptr)[20]) {
    if (cnt == 0) {
        printf("the database is empty\n");
        return;
    }

    char temp[20];
    fgets(temp, 20, stdin);
    if (temp[0] == '\n') fgets(temp, 20, stdin); // in case of leftover newline
    temp[strcspn(temp, "\n")] = '\0'; // safely remove newline

    int i = 0;
    int fd = 0;
    while (i != cnt) {
        if (strcmp(ptr[i], temp) == 0) {
            fd = 1;
            memmove(ptr[i], ptr[i + 1], (cnt - i - 1) *sizeof(*ptr)); // shift remaining names
            cnt--;
            continue; 
        }
        i++;
    }

    if (fd == 0) {
        printf("there is no name\n");
    }
}
void clearDB(char (*ptr)[20]){
    int i=0;
    while(i!=cnt){
        strcpy(ptr[i],"\0");
        i++;
    }
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main(){
    char ch;
    char names[MAX][20];
   
    while(1){
         printMenu();
    ch=getchar();
    clearInputBuffer();
   
    switch(ch){
        case 'i' : inputName(names);
                   break;
        case 'q' : exit(0);
        case 'p' : print(names);
                   break;
        case 's' : sort(names);
                   break;
        case 'd' : delete(names);
                   break;
        case 'c' : clearDB(names);
                   break;
        default  :printf("re enter the correct choice");

    }
}

}