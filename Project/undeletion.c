#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
int main()
{
	char c1,c2,target_file[20],command[100],file[7][200],try[400],words[2][20];
	int i,j,count,index;
	//string arr[6];
	//int file=open("Result", O_CREATE|O_WRONLY, S_IRWXU);
	//dup2()
	count =0;
	index=0;
	printf("enter file name:\n");
	fgets(target_file,20,stdin);
	
	target_file[strcspn(target_file,"\n")]=0;
	sprintf(command,"lsof | grep %s > log.txt",target_file);

	//sprintf(command,"lsof | grep %s > dude.txt",a);
	//system("lsof | grep \%s >> dude.txt");
	//system("lsof | grep \%s >> dude.txt",a);
	system(command);


	FILE *f=fopen ("log.txt","r");
	if (!f)
	printf ("error opening file\n");
	else
	{
		fgets(try,400,f);printf("%s",try);
		
		for (j=10;j<14;j++)
		{
			words[0][j-10]=try[j];
		}
		
		if (words[0][4]==" ")
		{
			words[1][0]=try[33];
		}
		
		else
		{
			words[1][0]=try[34];
			//words[1][1]=try[35];
		}
	}
	printf("Trying to recover....\n");
		sprintf(command,"cp /proc/%s/fd/%c recovery.txt",words[0],words[1][0]);
		if (system(command))
		printf("Failed to recover\n");
		else
		printf("Recovered successfully\n");	
	
	return 0;
}











