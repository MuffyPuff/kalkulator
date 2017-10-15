#include "function_t.h"
#include <QDebug>

function_t::function_t(QString pname, QString fname, QString body)
{
	function_name = fname;
	function_body = body;
	plugin_name = pname;
}


// TODO: execute code
QString
function_t::operator()()
{
	return function_body;
}

QString function_t::get_code()
{
	return function_body;
}
