#include "function_t.h"

#include <QFile>
#include <QTextStream>

function_t::function_t(QString pname, QString fname)
{
	function_name = fname;
	plugin_name = pname;

	QFile func("C:/Users/Muf/AppData/Roaming/MufCalc/plugins/" + pname + "/" + fname
	           + ".muf");
	func.open(QIODevice::ReadOnly);
	QTextStream is(&func);
	body = is.readAll();
	func.close();
}

QString
function_t::operator()()
{
	return body;
}
