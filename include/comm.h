#ifndef COMM_H
#define COMM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

#ifndef LOG_DIR
#define LOG_DIR			"..\\log\\"
#endif

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

typedef unsigned int	uint;
typedef unsigned int 	errcode;
typedef unsigned int	rtntype;
typedef unsigned char	schar;

/*
** define error code
*/
#define EC_SUCCESS (rtntype)0
#define EC_FAILURE (rtntype)1

#define ERR_STR_MAX_LEN	1024 /*max error info string length */
#define SQL_MAX_LEN		2048 /* max sql length */

/*
** define error type
*/
/*MySQL error code */
#define EC_MYSQL_CONNECTION_ERROR	0x0001
#define EC_MYSQL_SELECT_ERROR		0x0002
#define EC_MYSQL_INSERT_ERROR		0x0003
#define EC_MYSQL_UPDATE_ERROR		0x0004
#define EC_MYSQL_DELETE_ERROR		0x0005
#define EC_UNKNOWN_ERROR			0xffff

/* MySQL error type */
#define MYSQL_CONNECTION_ERROR	"MySQL connection error"
#define MYSQL_SELECT_ERROR		"MySQL select error"
#define MYSQL_INSERT_ERROR		"MySQL insert error"
#define MYSQL_UPDATE_ERROR		"MySQL update error"
#define MYSQL_DELETE_ERROR		"MySQL delete error"

#define UNKNOWN_ERROR_TYPE		"unknown error type"

/* encrypt string */
char *
encrypt(char const *string);

/* decrypt string */
char *
decrypt(char const *string);

/* show all query results on conn, and free result before return */
void
show_all_select_results(MYSQL *conn);

/* execute sql query on conn */
void
mysql_exe_query(MYSQL *conn, const char *sql);

#endif // !COMM_H
