#include "parser_t.h"
#include <QDebug>

parser_t::parser_t(QObject *parent)
        : QObject(parent)
{

}

QString
parser_t::operator()(QString expr)
{
	QRegExp fn("([a-zA-Z][a-zA-Z0-9]*)");
	QStringList functions;
	QList<int> positions;
	qint8 pos = 0;

	while ((pos = fn.indexIn(expr, pos)) != -1) {
		functions << fn.cap(1);
		positions << pos;

		expr.insert(pos, "Math.");
		pos += 5;

		pos += fn.matchedLength();
	}

//	foreach (QString el, functions) {
//		qDebug() << el;
//	}
	return expr;
}
