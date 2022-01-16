#pragma once

#include "SelectLabel.h"
#include "SelectWidget.h"
#include "TPlay.h"
#include "LogPanel.h"

namespace tt {

class PlayerController : public QMainWindow
{
public:
	PlayerController();
	~PlayerController();
	LogPanel& lp() { return *m_lp; }


protected:
	tt::TPlay*			m_player;
	tt::SelectLabel*	m_wdg_select_dir;		//btn_select + label
	tt::SelectWidget*	m_wdg_select_widget;

	tt::LogPanel*		m_lp;
}; // class PlayerController

} // namespace tt

