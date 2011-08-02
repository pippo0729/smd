#ifndef SM_MSG_PARSER_H
#define SM_MSG_PARSER_H

#include "str.h"

enum _rtsp_header_field_type	{
				HDR_CSEQ,
				HDR_SESSION,
				HDR_TRANSPORT,
				HDR_EXT_GLOBALSESSION
};

typedef enum _rtsp_header_field_type rtsp_header_field_type;


//------------- req enum -------------------------
enum rtsp_method	{
	METHOD_SETUP=1,
	METHOD_TEARDOWN=2,
	METHOD_GET_PARAMETER=4
};

//------------- header field(1st line) -------------------------
struct rtsp_firstline	{
				int type;
				int len;
				union	{
								struct	{
												str method;
												str uri;
												int methodvalue;
								} reqline;	//request line
								struct	{
												str version;
												str status;
												unsigned int statuscode;
								}statline;	//status line
				}u;
};


//------------- header field(other) -------------------------
struct rtsp_header_field	{
				rtsp_header_field_type type;
				str name;
				str body;
				int len;
				void* parsed;
				struct rtsp_header_field* next;	//next, diff type?
				struct rtsp_header_field* sibling;
};


//------------- whole msg -------------------------
struct rtsp_msg	{
				struct rtsp_header_field* cseq;
				struct rtsp_header_field* session;
};


//------------- macro define -------------------------
#define IFISMETHOD(methodname,firstchar)                                  \
				if (  (*tmp==(firstchar) || *tmp==((firstchar) | 32)) &&                  \
												strncasecmp( tmp+1, #methodname +1, methodname##_LEN-1)==0 &&     \
												*(tmp+methodname##_LEN)==' ') {                                   \
												printf("if yes\n");\
								fl->type=RTSP_REQ;                                     \
								fl->u.reqline.method.len=methodname##_LEN;                \
								fl->u.reqline.methodvalue=METHOD_##methodname;           \
								tmp=buffer+methodname##_LEN;                              \
				}
//------------- req const define -------------------------
#define RTSP_REQ 1


#define SETUP "SETUP"
#define TEARDOWN "TEARDOWN"
#define GET_PARAMETER "GET_PARAMETER"

#define SETUP_LEN 5
#define TEARDOWN_LEN 8
#define GET_PARAMETER_LEN 13


//------------- resp const define -------------------------
#define RTSP_RESP 2

#define RTSP_VERSION "RTSP/1.0"

#define RTSP_VERSION_LEN 8



char* parse_first_line(char* buffer, unsigned int len, struct rtsp_firstline* fl);


#endif
