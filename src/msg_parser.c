#include "str.h"
#include "msg_parser.h"
#include <string.h>
#include <stdio.h>


char* parse_first_line(char* buffer, unsigned int len, struct rtsp_firstline* fl)

{
				char* tmp;


				tmp=buffer;
				printf("111111111111111111\n");

				if((*tmp=='R' || *tmp=='r') && strncasecmp(tmp+1, RTSP_VERSION+1, RTSP_VERSION_LEN-1)==0	&& *(tmp+RTSP_VERSION_LEN)==' ')	{
								fl->type = RTSP_RESP;
								fl->u.statline.version.len = RTSP_VERSION_LEN;
				}
				else IFISMETHOD(SETUP, 'S')
				else IFISMETHOD(TEARDOWN, 'T')
				else IFISMETHOD(GET_PARAMETER, 'G')

				printf("2222222222222222222\n");

				return "";

}
