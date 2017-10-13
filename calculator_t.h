#ifndef CALCULATOR_T_H
#define CALCULATOR_T_H

#include <QObject>

#include <QScriptEngine>
#include <QTextStream>
#include <iostream>
#include <QString>

#include "parser_t.h"
#include "function_t.h"

class calculator_t : public QObject
{
	Q_OBJECT
public:
	explicit calculator_t(QObject *parent = nullptr);
	QString operator()(const QString &expr);
	QString parse(QString expr);
	void add_fn(QString pname, QString fname);

signals:

public slots:

private:
	parser_t parse;

	QList<QRegExp> rx_list;
	QMap<QString, function_t *> usr_fn;

};

#endif // CALCULATOR_T_H
