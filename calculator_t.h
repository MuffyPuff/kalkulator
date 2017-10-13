#ifndef CALCULATOR_T_H
#define CALCULATOR_T_H

#include <QObject>

#include <QScriptEngine>
#include <QTextStream>
#include <iostream>
#include <QString>

#include "parser_t.h"

class calculator_t : public QObject
{
	Q_OBJECT
public:
	explicit calculator_t(QObject *parent = nullptr);
	QString operator()(const QString &expr);

signals:

public slots:

private:
	parser_t parse;
};

#endif // CALCULATOR_T_H
