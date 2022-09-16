#include "handlers.h"

int is_sdcard_handler(http_request *request)
{
	if (!(startWith(request->path, "/sdcard/") && strlen(request->path) > 8)) 
		return 0;
	char *dup = strdup(request->path);
	
	char *p = strtok(dup+1, "/");
	p = strtok(NULL, "/"); // "sdcard/"
	
	FILE *fptr;
	fptr = fopen(p,"r");
	if (fptr == NULL) return 0;
	fclose(fptr);
	free(dup);
	return 1;
}
char *do_sdcard_request(char *path)
{
	char *dup = strdup(path);
	char *p = strtok(dup+1, "/");
	p = strtok(NULL, "/"); // "sdcard/"
	
	FILE *fptr = fopen(p,"r");
	//Thanks to Evie for helping me clean this clusterf*ck
	
	fseek(fptr,0,SEEK_END);
	size_t fileSize = ftell(fptr);
	printf("size_t: %u",fileSize);
	fseek(fptr, 0, SEEK_SET);
	
	/*
	Handle fptr;
	u64 fileSize;
	FSUSER_OpenFileDirectly(&fptr,ARCHIVE_SDMC,fsMakePath(PATH_EMPTY,""),fsMakePath(PATH_ASCII,p),FS_OPEN_READ,0);
	FSFILE_GetSize(fptr,&fileSize);
	FSFILE_Read(fptr,NULL,1,buffer,sizeof(buffer));
	*/

	char *buffer = (char *)memalloc(fileSize);
	size_t bytesRead = fread(buffer,1,fileSize,fptr);
	//printf("Sent: %s\n",buffer);
	if(fileSize!=bytesRead) failExit("Error reading file");
	//FSFILE_Close(fptr);
	fclose(fptr);
	free(dup);
	return buffer;
}
http_response *get_sdcard_response(http_request *request)
{
    http_response *response = memalloc(sizeof(http_response));
	response->code = 200;
	response->content_type = strdup("Content-Type: text/html\r\n");
	char * payload = do_sdcard_request(request->path);
    response->payload = payload;
	response->payload_len = strlen(payload);
	linearFree(payload);
	return response;    
}
