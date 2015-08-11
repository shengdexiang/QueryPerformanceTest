#ifndef ERR_H
#define ERR_H

#include "comm.h"

/* convert error types */
uint
convert_error_type(schar *error_type);

/* exit with report errors */
void
exit_with_error(MYSQL *conn);

#endif // !ERR_H
