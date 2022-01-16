#pragma once

#include <iostream>
#include <QLabel>
#include <string>
#include <QString>
#include <list>
#include <stdint.h>

#include "util.h"

/**
	log macro
*/
#define L_DEBUG LOG_DEBUG(lp())
#define L_ERROR LOG_ERROR(lp())
#define L_INFO  LOG_INFO(lp())


namespace tt  {
class LogPanel
{
public:
	typedef std::list<std::string> logco_t;
	LogPanel(QWidget* parent = nullptr);
	~LogPanel();

	void refresh();
	void setParent(QWidget* parent) { m_lab->setParent(parent); }

	LogPanel& operator<<(const std::string& str);
	LogPanel& operator<<(const QString& str);
	LogPanel& operator<<(const char* str);


private:
	QLabel*			m_lab;
	logco_t*		m_logs;
	uint64_t		m_line;
}; // class LogPanel

} // namespace tt