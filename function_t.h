#ifndef FUNCTION_T_H
#define FUNCTION_T_H

#include <QString>

class function_t
{
public:
	function_t(QString pname, QString fname, QString body);
	QString operator()();
	QString get_code();

private:
	QString function_name;
	QString plugin_name;
	QString function_body;
};

#endif // FUNCTION_T_H
