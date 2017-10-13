#ifndef FUNCTION_T_H
#define FUNCTION_T_H

#include <QString>

class function_t
{
public:
	function_t(QString pname, QString fname);
	QString operator()();

private:
	QString function_name;
	QString plugin_name;
	QString body;
};

#endif // FUNCTION_T_H
