
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "msg_parser.h"

int main(int argc, char* argv[])
{
  char* buf="TEARDOWN rtsp://192.168.8.159/smt.avi\r\nCSeq: 1\r\nSession: 112233\r\n\r\nthisisbodytext\r\n";
	char* v;
  struct rtsp_firstline* fl;
	printf("main 1\n");
  fl = (struct rtsp_firstline*)malloc(sizeof(struct rtsp_firstline));
	printf("main 2\n");
  v = parse_first_line(buf, 20, fl);
	printf("main 3\n");
	printf("msg type: %d\n",fl->u.reqline.methodvalue);
	printf("main 4\n");
	return 1;
}
