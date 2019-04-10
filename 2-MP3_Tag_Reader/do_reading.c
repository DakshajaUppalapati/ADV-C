#include <stdio.h>
#include "common.h"


Status do_reading(readInfo *readerInfo)
{
	//Declare variables here
	//Version version_status;
	int *p, size;
	int i = 0;
	//read_version_id(readerInfo);
	p = read_header_size(readerInfo);
	printf("%d\n", *p);
	size = *p;
	size = size + 10;
	while (ftell(readerInfo -> fptr_mp3) <= size)
	{	
		fread(readerInfo -> tag, 4, 1, readerInfo -> fptr_mp3);
		if (strcmp(readerInfo -> tag, "TALB") == 0)
		{
			view_details(readerInfo, "Album");
		}
		else if (strcmp(readerInfo -> tag, "COMM") == 0)
		{
			view_details(readerInfo, "Comment");
		}
		else if (strcmp(readerInfo -> tag, "TIT2") == 0)
		{
			view_details(readerInfo, "Title");
		}
		else if (strcmp(readerInfo -> tag, "TPE1") == 0)
		{
			view_details(readerInfo, "Artist");
		}
		else if (strcmp(readerInfo -> tag, "TYER") == 0)
		{
			view_details(readerInfo, "Year");
		}
		else if (strcmp(readerInfo -> tag, "TRCK") == 0)
		{
			view_details(readerInfo, "Track");
		}
		else if (strcmp(readerInfo -> tag, "TCOM") == 0)
		{
			view_details(readerInfo, "Genre");
		}
		//printf("%s", readerInfo -> tag);
	}
}

Status do_editing(readInfo *readerInfo, char *str, char *argv[])
{
	//Declare variables here
	//Version version_status;
	printf("\nhi\n");
	int *p, *size, size1, header_size;
	int len = 0;
	char ch = '\0';

	printf("In editing\n");
	//version_status = read_version_id(readerInfo);
	//fread(readerInfo -> tag, 4, 1, readerInfo -> fptr_mp3);
	size = read_header_size(readerInfo);
	printf("size = %d\n", *size);
	header_size = *size + 10;
	while (ftell(readerInfo -> fptr_mp3) <= header_size)
	{	
		printf("In while\n");
		fread(readerInfo -> tag, 4, 1, readerInfo -> fptr_mp3);
		if (strcmp(readerInfo -> tag, str) == 0)
		{
			printf("In if\n");
			printf("%s\n", readerInfo -> tag);
			printf("after if\n");
			p = read_header_size(readerInfo);
			printf("%d\n", *p);
			size1 = *p;
			len = strlen(argv[4]);
			fseek(readerInfo -> fptr_mp3, 2, SEEK_CUR);
			fwrite(argv[4], len, 1, readerInfo -> fptr_mp3);
			for (;++len <= size1;)
				fwrite(&ch, 1, 1, readerInfo -> fptr_mp3);
			break;
		}
		else
		{
			printf("In else\n");
			p = read_header_size(readerInfo);
			printf("%d\n", *p);
			size1 = *p;
			size1 = 2 + size1;
			printf("%d\n", size1);
			fseek(readerInfo -> fptr_mp3, size1, SEEK_CUR);
			printf("%ld\n", ftell(readerInfo -> fptr_mp3));
			
		}
		
	}
	//fseek(readerInfo -> fptr_mp3, 10, SEEK_SET);
}
	
