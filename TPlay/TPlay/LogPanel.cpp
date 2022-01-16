#include "LogPanel.h"
#include <sstream>
namespace tt {



tt::LogPanel::LogPanel(QWidget* parent)
{
	m_logs = new logco_t;
	m_lab = new QLabel(parent);
	m_line = 0;

	m_lab->setText("LogPanel");
	m_lab->resize(800, 300);
	m_lab->move(1200, 0);
}

tt::LogPanel::~LogPanel()
{
	if(m_logs)
		delete m_logs;
	m_line = 0;
}

void LogPanel::refresh()
{
	std::stringstream ss;
	for (auto it : *m_logs) {
		ss << it;
	}
	ss << "\nline = " << m_line;
	m_lab->setText(ss.str().c_str());
}

LogPanel& tt::LogPanel::operator<<(const std::string& str)
{
	m_logs->push_back(str);
	m_line++;
	refresh();
	return *this;
}

LogPanel& tt::LogPanel::operator<<(const QString& str)
{
	return (*this) << (str.toStdString());
}

LogPanel& tt::LogPanel::operator<<(const char* str)
{
	return (*this) << (std::string(str));
}

} // namespace tt