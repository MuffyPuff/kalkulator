#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <QScriptEngine>
#include <QTextStream>
#include <iostream>
#include <cstdio>
#include <QRegExp>
#include <QFile>

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
	QFile input("D:/Muf/Workspace/kalkulator/input.in");
	input.open(QIODevice::ReadOnly);
	QTextStream qStdIn(&input);
	QTextStream is(stdin);
	calculator_t calc;

	while (true) {
		if (qStdIn.atEnd()) {
			qStdIn.setDevice(is.device());
		}

		// Read input
		QString expr = qStdIn.readLine();

//		if (expr == "postfix" || expr == "RPN") {
//			continue;
//		}

		// Calculate and output
		QTextStream qStdOut(stdout);
		qStdOut << "--> " << calc(expr) << '\n';
	}

	return a.exec();
}
