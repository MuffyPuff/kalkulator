#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QScriptEngine>
#include <QTextStream>
#include <iostream>
#include <cstdio>
#include <QRegExp>

#include "calculator_t.h"

//QString
//calc(QString expr)
//{
//	QScriptEngine expression;
//	return expression.evaluate(parser_t::parse(expr)).toString();
//}

int
main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QTextStream qStdIn(stdin);
	calculator_t calc;
	calc.add_fn("Muf", "test");

	while (true) {
		QString expr = qStdIn.readLine();

//		if (expr == "postfix" || expr == "RPN") {
//			continue;
//		}

		QTextStream qStdOut(stdout);
		qStdOut << "--> " << calc(expr) << '\n';
	}

	return a.exec();
}
