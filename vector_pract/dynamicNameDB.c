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
void sort(char **ptr){
    char* temp;
    for(int i=0;i<cnt;i++){
        for(int j=0;j<cnt-i-1;j++){
            if(strcmp(ptr[j],ptr[j+1])>0){
                temp=ptr[j];
                ptr[j]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }

    }
}
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void delete(char **ptr){
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
            memmove(ptr+i,ptr+(i+1),(cnt-i-1)*sizeof(*ptr));
            cnt--;
            i--;
        }
    }   
    ptr=realloc(ptr,(cnt*sizeof(*ptr)));
}
char ** input(char **ptr){
    ptr=(char **)realloc(ptr,(cnt+1)*sizeof(*ptr));
    if(!ptr){
        printf("Memory allocation  is failed");
        return ptr;
    }
    ptr[cnt]=(char*)malloc(20*sizeof(char));
    if(!ptr[cnt]){
        printf("memory allocation is failed");
        return ptr;
    }
    fgets(ptr[cnt],20,stdin);                                               
    ptr[cnt][strlen(ptr[cnt])-1]='\0';
    ptr[cnt]=realloc(ptr[cnt],strlen(ptr[cnt])+1);
    cnt++;
    return ptr;

}
void print(char **ptr){
    for(int i=0;i<cnt;i++){
        printf("%s\n",ptr[i]);
    }
}
int main(){
    char ch;
    char ** names=NULL;
   
    while(1){
         printMenu();
         ch=getchar();
         clearInputBuffer();
   
    switch(ch){
        case 'i' : names=input(names);
                   break;
        case 'p' : print(names);
                   break;
        case 'q':
                for (int i = 0; i < cnt; i++) {
                    free(names[i]);
                }
            free(names);
            exit(0);

        case 's' : sort(names);
                   break;
        case 'd' : delete(names);
                   break;
        // case 'c' : clearDB(names);
        //            break;
        default  :printf("re enter the correct choice");

    }
}

}