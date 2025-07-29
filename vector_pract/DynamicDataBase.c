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
void print(char (*ptr)[20]){
    if(cnt==0){
        printf("no names in the databases");
        return ;
    }
    for(int i=0;i<cnt;i++){
        printf("%s\n",ptr[i]);
    }
}
void delete(char (*ptr)[20]){
    if(cnt==0){
        printf("data base is empty");
        return;
    }
    // char (*str)[20]=ptr;
    char temp[20];
    fgets(temp,20,stdin);
    temp[strlen(temp)-1]='\0';
    for(int i=0;i<cnt;i++){
        if(strcmp(ptr[i],temp)==0){
            memmove(ptr[i],ptr[i+1],(cnt-i-1)*sizeof(*ptr));
            cnt--;
        }
    }   
    ptr=(char (*)[20])realloc(ptr,(cnt*sizeof(*ptr)));
}
void* input(char (*ptr)[20]){
    ptr=(char (*)[20])realloc(ptr,(cnt+1)*sizeof(*ptr));
    fgets(ptr[cnt],20,stdin);
    ptr[cnt][strlen(ptr[cnt])-1]='\0';
    cnt++;
    return ptr;

}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void clearDB(char (*ptr)[20]){
    int i=0;
    while(i!=cnt){
        strcpy(ptr[i],"\0");
        i++;
    }
}
int main(){
    char ch;
    char (*names)[20]=NULL;
   
    while(1){
         printMenu();
    ch=getchar();
    clearInputBuffer();
   
    switch(ch){
        case 'i' : names=input(names);
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