#include"functions_for_cmd_typist.h"

void select_lesson(int argc_cmd)
	{
		if(argc_cmd>0&&argc_cmd<4)//checking on the command line argument.
		{				
			char ch;//
			printf("%s", "Enter command >>");
			while(scanf("%s",firstarg)!=1||(scanf("%d",&lesson_choice))!=1||lesson_choice<1||lesson_choice>15||strncmp(firstarg,"select",6)!=0)//Ensuring that "select" 
			{       						//is entered accurately and the selected value is within the correct range.
				                   
			    if((strncmp(firstarg,"se",2)==0||strcmp(firstarg,"sel")==0||strcmp(firstarg,"sele")==0||strcmp(firstarg,"selec")==0)&&strcmp(firstarg,"select")!=0)
			    											//Making suggestion to help user prevent errors.
						fprintf(stderr, "\n%s\n", "Did you mean \"select usernumber\"");
				else if(ch!=1&&strcmp(firstarg,"select")==0)
				  printf("%s", "Lesson number cannot contain symbols or alphas\n");
				else if((lesson_choice<1||lesson_choice>20)&&strcmp(firstarg,"select")==0)
					fprintf(stderr, "%s %d\n", "No lesson entry for ",lesson_choice);
				else printf("%s\n", "Command not found");
				while(ch=getchar()!='\n');//disposing off wrong input string.
			}
		}
		else
		{
			fprintf(stderr, "%s\n", "Invalid number of arguments, consult \"cmdtypist --help\" for more");
			exit(EXIT_FAILURE);
		}
			/*
			if(argc_cmd==3)
				if(strncmp(argv[2],"select",6)!=0||lesson_choice<1||lesson_choice>20)
				{
					fprintf(stderr, "%s\n", "Command not found\n");
					if(strncmp(argv[2],"se",2))
						fprintf(stderr, "%s\n", "Did you mean \"select\"");
					else if(lesson_choice<1||lesson_choice>20)
						fprintf(stderr, "%s %d\n", "No lesson entry for ",lesson_choice);
					//else if(ch!=1)
				        printf("%s", "Lesson number cannot contain symbols or alpha letters.\n");
					exit(EXIT_FAILURE);
				}*/
		printf("\n");
	}

void urs_or_cchl(void)
{
	if(read_myown_config()==0)
	{
		strcpy(file_to_read,"my_own.txt");
		mode=1;
	}
	else if(read_myown_config()==1)
			strcpy(file_to_read,"noslaclessons.txt");
	else
	{
		fprintf(stderr, "%s\n", "Fatal Error, lesson file corrupted or does not exist");
		exit(EXIT_FAILURE);
	}
}

