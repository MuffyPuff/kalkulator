#ifndef PLUGIN_HANDLER_T_H
#define PLUGIN_HANDLER_T_H

#include <QRegExp>
#include <functional>

class plugin_handler_t
{
public:
	plugin_handler_t();

	QRegExp match;
	std::function<QString(Qstring...)> handle;
};

#endif // PLUGIN_HANDLER_T_H
