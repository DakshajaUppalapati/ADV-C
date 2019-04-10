/*
	Title		:	main_function
	Author		:	Dakshaja U
	Organisation	:	Emertxe
	Description	:	
*/

#include "common.h"

//Open_files function
Status open_files(readInfo *readerInfo, char *argv[], char *str);

void print_help_options(char *argv[]);

void read_version_id(readInfo *readerInfo);

void* read_header_size(readInfo *readerInfo);

Status do_reading(readInfo *readerInfo);

Status do_editing(readInfo *readerInfo, char *str, char *argv[]);

void view_details(readInfo *readerInfo, char *str);

//void print_tag_content(readInfo *readerInfo);

void edit_details(readInfo *readerInfo, char *str);

