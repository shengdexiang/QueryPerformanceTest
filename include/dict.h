#ifndef DICT_H
#define DICT_H

#include "comm.h"

/* show all query results */
void
show_all_select_results(MYSQL *conn);

/* execute sql query */
void
mysql_exe_query(MYSQL *conn, const char *sql);

#endif