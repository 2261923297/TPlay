#pragma once
#include <qpushbutton.h>
#include <qlabel.h>
#include <string>

#include "LogPanel.h"

namespace tt {

class SelectLabel : public QWidget
{
public:
	SelectLabel(QWidget* parent = nullptr);
	~SelectLabel();

	void set_cur_dir(const std::string& cur_dir);
	const std::string& cur_dir() const { return m_cur_dir; }

	LogPanel& lp() { return *m_lp; }

public slots:
	void on_btn_select_clicked();

protected:
	std::string		m_cur_dir;
	QPushButton*	m_btn_select;
	QLabel*			m_lbl_cur_dir;
	tt::LogPanel*	m_lp;
	
}; // class SelectLabel


} // namespace tt 
