/*h
	Title		:	main_function
	Author		:	Dakshaja U
	Organisation	:	Emertxe
	Description	:	
*/

#ifndef COMMON_H
#define COMMON_H

typedef struct
{
	char *mp3_fname;
	FILE *fptr_mp3;
	char tag[4];
	int *size;
	int *size_header;
}readInfo;

typedef enum
{
	version2_3,
	version2_4
}Version;

typedef enum
{
	e_success,
	e_failure
}Status;

typedef struct
{
	char tag[4];
	int *size;
}frame_t;

#endif
