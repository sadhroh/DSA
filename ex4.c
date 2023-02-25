#include<stdio.h>
#include<malloc.h>
#include<string.h>

int isInteger(char *str){
	int check,index;
	check=index=0;
	if(str[index]=='-')
		index++;
	while(str[index]!='\0'){
		if(str[index]<48 || str[index]>57)
			break;
		index++;
	}
	if(index==strlen(str))
		check = 1;
	
	return check;
}

int isFloat(char *str){
	int check,index,dotFlag;
	check=index=dotFlag=0;
	if(str[index]=='-')
		index++;
	while(str[index]!='\0'){
		if(str[index]=='.')
			dotFlag++;
		else if(str[index]<48 || str[index]>57)
			break;
		index++;
	}
	if(index==strlen(str) && dotFlag==1)
		check = 1;
	
	return check;
}

int isString(char *str){
	int check,index;
	check=index=0;
	while(str[index]!='\0'){
		if(str[index]!='_'){
			if(str[index]<65 || str[index]>90){
				if(str[index]<97 || str[index]>122)
					break;
			}
		}
		index++;
	}
	if(index==strlen(str))
		check = 1;
	
	return check;
}

void main(int argc,char *argv[]){
	char *str;
	int ch,ind;
	ind = -1;
	str = NULL;
	while((ch=getchar()) != '\n'){
		ind++;
		if(str==NULL){
			str = (char*)malloc(sizeof(char)*2);
		}
		else{
			str = (char*)realloc(str,strlen(str)+1);
		}
		str[ind] = ch;
	}
	str[++ind] = '\0';
	if(isInteger(str)==1){
		printf("Argument is an integer");
	}
	else if(isFloat(str)==1){
		printf("Argument is a floating point number");
	}
	else if(isString(str)==1){
		printf("Argument is a string");
	}
	else{
		printf("Argument is invalid type");
	}
	free(str);
	str = NULL;
}
