#include "..\\include\\dict.h"

void
show_all_select_results(MYSQL *conn)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	uint num_fields;

	res = mysql_store_result(conn);
	num_fields = mysql_num_fields(res);

	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	mysql_free_result(res);
	return;
}

void
mysql_exe_query(MYSQL *conn, const char *sql)
{
	if (mysql_query(conn, sql))
	{
		exit_with_error(conn);
	}
	return;
}