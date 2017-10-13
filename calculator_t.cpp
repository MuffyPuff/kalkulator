#include "calculator_t.h"

calculator_t::calculator_t(QObject *parent) : QObject(parent)
{

}

QString
calculator_t::operator()(const QString &expr)
{
	QScriptEngine expression;
	QTextStream qStdOut(stdout);
	return expression.evaluate(parse(expr)).toString();
}
