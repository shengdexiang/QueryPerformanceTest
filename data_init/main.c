#define _CRT_SECURE_NO_WARNINGS
#include "..\\include\\aes.h"
#include "..\\include\\dict.h"
#include "..\\include\\err.h"
#include "..\\include\\md5.h"
#include "..\\include\\sha1.h"

#define READ_LENGTH_EACH_TIME	50	 /* string length read from file each time */
#define READ_TOTAL_TIMES		200	 /* total read times from file */
#define DEBUG_PRINT(string) printf("In %s", (string))

/* datasource and MySQL connection settings */
char const *english_char_source = "..\\novel\\tpch_results.txt";
char const *chinese_char_source = "..\\novel\\°×ÂíÐ¥Î÷·ç.txt";
const char *host_name = "localhost";
const char *user_name = "root";
const char *password = "root";
const char *database = "test";
const uint *port = 3306;

rtntype
main(uint argc, char *argv[])
{
	FILE *fp = NULL;
	MYSQL *conn = NULL;
	MYSQL_RES *res = NULL;
	MYSQL_ROW row = NULL;
	uint num_fields = 0;
	schar sql[SQL_MAX_LEN];
	schar error_type[ERR_STR_MAX_LEN];
	char buf[READ_LENGTH_EACH_TIME + 1] = { 0 };
	int read_times = 0;
	
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		exit_with_error(conn);
	}
	
	if (mysql_real_connect(conn, host_name, user_name, password, database, port, NULL, 0) == NULL)
	{
		exit_with_error(conn);
	}

	/* show databases */
	strcpy(sql, "show databases;");
	mysql_exe_query(conn, sql);
	show_all_select_results(conn);

	printf("Initializing data ......\n");
	fp = fopen(english_char_source, "r");
	read_times = 0;  /* read times from file */
	while (fp != EOF) {
		fread(buf, sizeof(char), READ_LENGTH_EACH_TIME, fp);
		printf("%s\n", buf);
		read_times++;
		if (read_times > READ_TOTAL_TIMES) {
			break;
		}
	}

	fclose(fp);
	mysql_close(conn);
	getchar();

	EC_SUCCESS;
}

char *
encrypt(char const *string)
{
	DEBUG_PRINT("encrypt()");
	return "";
}

char *
decrypt(char const *string)
{
	DEBUG_PRINT("decrypt()");
	return "";
}