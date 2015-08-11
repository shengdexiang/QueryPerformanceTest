#define _CRT_SECURE_NO_WARNINGS
#include "..\\include\\err.h"

void
exit_with_error(MYSQL *conn)
{
	fprintf(stderr, "%s\n", mysql_error(conn));
	mysql_close(conn);
	exit(EC_FAILURE);
}

uint
convert_error_type(schar *error_type)
{
	if (_stricmp(error_type, MYSQL_CONNECTION_ERROR) == 0)
	{
		return EC_MYSQL_CONNECTION_ERROR;
	}
	else if (_stricmp(error_type, MYSQL_SELECT_ERROR) == 0)
	{
		return EC_MYSQL_SELECT_ERROR;
	}
	else if (_stricmp(error_type, MYSQL_INSERT_ERROR) == 0)
	{
		return EC_MYSQL_INSERT_ERROR;
	}
	else if (_stricmp(error_type, MYSQL_UPDATE_ERROR) == 0)
	{
		return EC_MYSQL_UPDATE_ERROR;
	}
	else if (_stricmp(error_type, MYSQL_DELETE_ERROR) == 0)
	{
		return EC_MYSQL_DELETE_ERROR;
	}
	else
	{
		return EC_UNKNOWN_ERROR;
	}
}