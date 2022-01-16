#include "PlayerController.h"

namespace tt {

PlayerController::PlayerController()
{
	this->resize(1920, 1080);
	m_lp = GetPoint<LogPanel>();
	m_lp->setParent(this);


	m_player = new TPlay(this);

	//m_wdg_select_dir = new SelectLabel(this);
	//m_wdg_select_widget = new SelectWidget(this);

	
}


PlayerController::~PlayerController()
{
}


} // namespace tt
