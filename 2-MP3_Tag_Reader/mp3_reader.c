/*
	Title		:	mp3_reader.c
	Author		:	Dakshaja U
	Organisation	:	Emertxe
	Description	:	
*/

#include "mp3_reader.h"

Status open_files(readInfo *readerInfo, char *argv[], char *mode)
{
	printf("Open Files\n");
	readerInfo -> mp3_fname = argv[2];
	readerInfo -> fptr_mp3 = fopen(readerInfo -> mp3_fname, mode);
	if (readerInfo -> fptr_mp3 == NULL)
	{
		return e_failure;
	}
	return e_success;
}

void print_help_options(char *argv[])
{
	printf("Help Menu for mp3 Tag reader and Editor\n\n");
	printf("For viewing the tags-	./mp3_tag_reader -v <.mp3 file>\n\n");
	printf("For editing the tags-	./mp3_tag_reader -e <.mp3 file> <modifier> <tag>\n\n");
	printf("\tModifier\t\tFunction\n");
	printf("\t   -t\t\tModifies Title tag\n");
	printf("\t   -T\t\tModifies Track tag\n");
	printf("\t   -a\t\tModifies Artist tag\n");
	printf("\t   -A\t\tModifies Album tag\n");
	printf("\t   -y\t\tModifies year tag\n");
	printf("\t   -c\t\tModifies Comment tag\n");
	printf("\t   -g\t\tModifies Genre tag\n");
}

void read_version_id(readInfo *readerInfo)
{
	char buff[5];
	fread(buff, 6, 1,readerInfo -> fptr_mp3);
	printf("Version ID: 2.");
	printf("%d\n", buff[3]);
	/*if (buff[3] == 3)
	{
		return version2_3;
	}
	else if (buff[3] == 4)
	{
		return version2_4;
	}*/
}

void *read_header_size(readInfo *readerInfo)
{
	unsigned char buff[4];
	unsigned char temp;
	int j;
	void *p = buff;
	fread(buff, 4, 1,readerInfo -> fptr_mp3);
	for (int i = 0, j = 4 - 1; i <= j; i++, j--)
	{
		temp = buff[i];
		buff[i] = buff[j];
		buff[j] = temp;
	}
	return p;
	
}

void view_details(readInfo *readerInfo, char *str)
{
	int size;
	readerInfo -> size = read_header_size(readerInfo);
	size = *(readerInfo -> size);
	char tag_content[size];
	fseek(readerInfo -> fptr_mp3, 2, SEEK_CUR);
	fread(tag_content, size, 1, readerInfo -> fptr_mp3);
	printf("size in view = %d\n", size);
	printf("%s: ", str);
	for (int i = 0; i < size; i++)
	{
		if (tag_content[i] >= 33 && tag_content[i] < 127)
		{
			printf("%c", tag_content[i]);
		}
	}
	printf("\n");
}


/*void edit_details(readInfo *readerInfo, char *str)
{
	int size, str_length;
	//char *new_str;
	readerInfo -> size = read_header_size(readerInfo);
	size = *(readerInfo -> size);
	char tag_content[size];
	fseek(readerInfo -> fptr_mp3, 2, SEEK_CUR);
	//fread(tag_content, size, 1, readerInfo -> fptr_mp3);
	printf("Enter %s: ", str);
	scanf("%s", tag_content);
	str_length = strlen(tag_content);
	fwrite(tag_content, str_length, 1, readerInfo -> fptr_mp3);
}*/
