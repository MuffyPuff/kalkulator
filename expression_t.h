#ifndef EXPRESSION_T_H
#define EXPRESSION_T_H

#include <QString>

class expression_t
{
public:
	expression_t();
	void set(const QString &expr);
	QString eval();


private:
	expression_t *m_lhs; // can be null
	expression_t *m_rhs; // can be null
	QString m_type;
	QString m_value; // can be null
};

#endif // EXPRESSION_T_H
