#pragma once

#include <QMediaPlayer>
#include <QMainWindow>
#include <QVideoWidget>
#include <QPushButton>
#include <QLabel>

#include "SelectWidget.h"
#include "SelectLabel.h"

namespace tt {
class LogPanel;
class TPlay : public QMainWindow
{
	Q_OBJECT
public:
	TPlay(QWidget* parent = nullptr);
	~TPlay();
	LogPanel& lp() { return *m_lp; }
	void setRSPath(const std::string& rs_path);
	
	const std::string& getRSPath() const { return m_rs_path; }

	void play(const std::string& rs_path);

private:
	LogPanel*			m_lp;

	QMediaPlayer*		m_player;  
	QAudioOutput*		m_aop;   
	QVideoWidget*		m_vw;   

	std::string			m_rs_path;

	tt::SelectWidget*	m_sw;

	tt::SelectLabel*	m_sl;

}; // class TPlay


} // namespace tt