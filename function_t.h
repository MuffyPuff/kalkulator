#ifndef FUNCTION_T_H
#define FUNCTION_T_H

#include <QString>

#include "global_values.h"

class function_t
{
public:
	function_t(QString pname, QString fname, QString body);
	QString operator()();
	QString get_code();
	QString handle(QString params);

private:
	QString function_name;
	QString plugin_name;
	QString function_body;
	qint8 param_count;
};

#endif // FUNCTION_T_H
