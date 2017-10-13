#include "calculator_t.h"

calculator_t::calculator_t(QObject *parent) : QObject(parent)
{
	rx_list.append(QRegExp("([a-zA-Z][a-zA-Z0-9]*)"));
}

QString
calculator_t::operator()(const QString &expr)
{
	QScriptEngine expression;
	return expression.evaluate(parse(expr)).toString();
}

QString
calculator_t::parse(QString expr)
{
	QStringList results;
	QList<int> positions;
	qint8 pos = 0;

	foreach (QString key, usr_fn.keys()) {
		QRegExp rx(key);
//		qDebug() << key;
//		qDebug() << rx;
//		qDebug() << rx_list.first();

		while ((pos = rx.indexIn(expr, pos)) != -1) {
			QString fn = rx.cap(0);
//			qDebug() << fn;
			function_t *func = usr_fn[fn];
			QString res = func->operator()();
//			qDebug() << res;
			expr.replace(fn, this->operator()(res));
			pos += res.length();
		}
	}

	pos = 0;
	foreach (QRegExp rx, rx_list) {
		while ((pos = rx.indexIn(expr, pos)) != -1) {
			results << rx.cap(0);
			positions << pos;

			expr.insert(pos, "Math.");
			pos += 5;

			pos += rx.matchedLength();
		}
	}

	foreach (QString el, results) {
		qDebug() << el;
	}
	return expr;
}

void
calculator_t::add_fn(QString pname, QString fname)
{
	usr_fn.insert(fname, new function_t(pname, fname));
}
