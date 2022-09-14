#include "handlers.h"

char *append( char *str, char ch )
{
    int length = strlen( str );
    char *str2;

    str2 = ( char * )memalloc(( length + 2 ) * sizeof( char ) );
    if (!str2) {
		printf("b");
        free(str);
        return NULL;
    }
    strcpy(str2,str);
    str = str2;

    str[length] = ch;
    str[length+1] = '\0';
    return str;
}
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
char *do_sdcard_request(char *path, char *outbuf)
{
	char *dup = strdup(path);
	char *p = strtok(dup+1, "/");
	p = strtok(NULL, "/"); // "sdcard/"
	
	FILE *fptr;
	fptr = fopen(p,"r");
	char c;
	c = fgetc(fptr);
	while (!feof(fptr)) {
		outbuf = append(outbuf, c);
		c = fgetc(fptr);
	}
	printf("Sent: %s\n",outbuf);
	fclose(fptr);
	free(dup);
	return outbuf;
}
http_response *get_sdcard_response(http_request *request)
{
    http_response *response = memalloc(sizeof(http_response));
	response->code = 200;
	response->content_type = strdup("Content-Type: text/html\r\n");
    char *payload = (char *) memalloc(1024 * sizeof(char));
    payload = do_sdcard_request(request->path, payload);
    response->payload = payload;
	response->payload_len = strlen(payload);
	return response;    
}
