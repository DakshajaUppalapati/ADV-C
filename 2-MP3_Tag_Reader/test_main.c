/*
	Title		:	main_function
	Author		:	Dakshaja U
	Organisation	:	Emertxe
	Description	:	
*/


#include <stdio.h>
#include <string.h>
#include "common.h"
#include "mp3_reader.c"
#include "do_reading.c"

int main(int argc, char *argv[])
{
	//printf("In main\n");
	//Declare variables here
	readInfo readerInfo;
	Status status_open_files;
	char p[10000];
	
	if (strcmp(argv[1],"-h") == 0)
	{
		print_help_options(argv);
		return 0;
	}
	else if (strcmp(argv[1], "-v") == 0)
	{
		status_open_files = open_files(&readerInfo, argv, "rb");
		read_version_id(&readerInfo);
		do_reading(&readerInfo);
	}
	else if (strcmp(argv[1], "-e") == 0)
	{
		status_open_files = open_files(&readerInfo, argv, "rb+");
		read_version_id(&readerInfo);
		if (strcmp(argv[3], "-t") == 0)
		{
			printf("in -t\n");
			//printf("Enter tag_content: ");
			//scanf("%s", p);
			do_editing(&readerInfo, "TIT2", argv);
		}
		else if (strcmp(argv[3], "-T") == 0)
		{
			printf("in -T\n");
			//printf("Enter tag_content: ");
			//scanf("%s", p);
			do_editing(&readerInfo, "TRCK", argv);
		}
		else if (strcmp(argv[3], "-a") == 0)
		{
			printf("in -a\n");
			//printf("Enter tag_content: ");
			//scanf("%s", p);
			do_editing(&readerInfo, "TPE1", argv);
		}
		else if (strcmp(argv[3], "-A") == 0)
		{
			printf("in -A\n");
			//printf("Enter tag_content: ");
			//scanf("%s", p);
			do_editing(&readerInfo, "TALB", argv);
		}
		else if (strcmp(argv[3], "-c") == 0)
		{
			printf("in -c\n");
			//printf("Enter tag_content: ");
			//scanf("%s", p);
			do_editing(&readerInfo, "COMM", argv);
		}
		else if (strcmp(argv[3], "-g") == 0)
		{
			printf("in -g\n");
			//printf("Enter tag_content: ");
			//scanf("%s", p);
			do_editing(&readerInfo, "TCOM", argv);
		}
		else 
		{
			printf("<./a.out> <-e> <file.mp3> <tag option> <Tagcontent>");
		}
		
		//fseek(readerInfo.fptr_mp3, 0, SEEK_SET);
		//do_reading(&readerInfo);
		
	}
	//printf("After open files\n");
	if (status_open_files == e_failure)
	{
		return 255;
	}
	
	
	
}
