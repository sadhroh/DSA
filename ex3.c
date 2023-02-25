#include<stdio.h>
#include<malloc.h>
#include<string.h>

int isOctal(char *line){
	int index = 1;
	while(line[index]!='\0'){
		if(line[index]<48 || line[index]>55)
			break;
		index++;
	}
	if(index==strlen(line))
		return 1;
	else
		return 0;
}

int isHexa(char *line){
	int index = 2;
	while(line[index]!='\0'){
		if(line[index]<48 || line[index]>57 && (line[index]<65 || line[index]>70) && (line[index]<97 || line[index]>102)){
			//if(line[index]!='a' && line[index]!='b' && line[index]!='c' && line[index]!='d' && line[index]!='e' && line[index]!='f' && line[index]!='A' && line[index]!='B' && line[index]!='C' && line[index]!='D' && line[index]!='E' && line[index]!='F')
				break;
		}
		index++;
	}
	if(index==strlen(line))
		return 1;
	else
		return 0;
}

int isDeci(char *line){
	int index = 0;
	while(line[index]!='\0'){
		if(line[index]<48 || line[index]>57)
			break;
		index++;
	}
	if(index==strlen(line))
		return 1;
	else
		return 0;
}

int isBinary(char *line){
	int index = 1;
	while(line[index]!='\0'){
		if(line[index]<48 || line[index]>49)
			break;
		index++;
	}
	if(index==strlen(line))
		return 1;
	else
		return 0;
}

void main(int argc,char *argv[]){
	int lineNo,ind,c;
	char *line;
	FILE *fp;
	lineNo = ind = 0;
	line = NULL;
	fp = fopen("test.txt","r");
	if(fp==NULL)
	{
		printf("File could not be loaded");
		return;
	}
	do{
		c = fgetc(fp);
		if(c!='\n'){
			if(line==NULL){
				line = (char*)malloc(sizeof(char)*2);
			}
			else{
				line = (char*)realloc(line,strlen(line)+1);
			}
			line[ind] = c;
			ind++;
		}
		else{
			lineNo++;
			line[ind] = '\0';
			ind = 0;
			if(line[ind]=='b'){
				if(isBinary(line)!=1){
					printf("\n%d: %s - invalid binary number",lineNo,line);
				}
			}
			else if(line[ind]=='0'){
				if(line[ind+1]=='x' || line[ind+1]=='X'){
					if(isHexa(line)!=1){
						printf("\n%d: %s - invalid hexa number",lineNo,line);
					}
				}
				else if(isOctal(line)!=1){
					printf("\n%d: %s - invalid octal number",lineNo,line);
				}
			}			
			else if(isDeci(line)!=1){
				printf("\n%d: %s - invalid prefix",lineNo,line);
			}
			free(line);
			line = NULL;
		}
	}while(!feof(fp));
	fclose(fp);
	free(fp);
	fp = NULL;
}
