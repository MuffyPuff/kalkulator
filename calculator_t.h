#ifndef CALCULATOR_T_H
#define CALCULATOR_T_H

#include <QObject>

#include <QScriptEngine>
#include <QTextStream>
#include <iostream>
#include <QString>
#include <QList>
#include <QDir>
#include <QRegExp>

#include "function_t.h"

class calculator_t : public QObject
{
	Q_OBJECT
public:
	explicit calculator_t(QObject *parent = nullptr);
	void load_plugins();
	void add_plugin(QString pname);
	void add_plugin(QDir plugin);
	void add_fn(QString pname, QString fname, QString body);
	QString operator()(const QString &expr);
	QString parse(QString expr);

signals:

public slots:

private:
	QList<QRegExp> rx_list;
	QMap<QString, function_t *> usr_fn;

};

#endif // CALCULATOR_T_H
