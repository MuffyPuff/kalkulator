#ifndef PARSER_T_H
#define PARSER_T_H

#include <QObject>
#include <QString>
#include <QList>
#include <QRegExp>

class parser_t : public QObject
{
	Q_OBJECT
public:
	explicit parser_t(QObject *parent = nullptr);
	QString operator()(QString expr);

signals:

public slots:

private:
	QList<QRegExp> rx_list;
};

#endif // PARSER_T_H
