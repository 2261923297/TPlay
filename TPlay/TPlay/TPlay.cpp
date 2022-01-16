
#include "TPlay.h"
#include "LogPanel.h"
#include "util.h"
#include <QAudioOutput>
#include <qthread.h>

namespace tt {

TPlay::TPlay(QWidget* parent)
{
	setParent(parent);

	this->resize(1920, 1080);
	m_lp = GetPoint<LogPanel>();
	m_lp->setParent(this);
	m_sw = new tt::SelectWidget(this);
	


//	setRSPath("E:\\resource\\videoplay\\videos\\11.mp4");

	m_player = new QMediaPlayer(this);
	m_aop = new QAudioOutput;
	m_vw = new QVideoWidget(this);

	m_player->setAudioOutput(m_aop);
	m_player->setVideoOutput(m_vw);

	
	connect(m_player, SIGNAL(positionChanged(qint64)), 
		this, SLOT(positionChanged(qint64)));

	m_aop->setVolume(100);

	m_vw->setGeometry(0, 50, 800, 600);
	m_sw->setGeometry(800, 50, 300, 600);
	m_sw->add_item_from_file("E:\\resource\\videoplay\\videos\\");
	m_sw->setFont(QFont("Î¢ÈíÑÅºÚ", 14));

	m_sl = new SelectLabel(this);
	m_sl->setGeometry(0, 10, 600, 20);

	m_player->play();

}

TPlay::~TPlay()
{

}

void TPlay::setRSPath(const std::string& rs_path)
{
	m_rs_path = rs_path;
	m_sl->set_cur_dir(m_rs_path.c_str());
}

void TPlay::play(const std::string& rs_path)
{
	setRSPath(rs_path);
	m_player->setSource(QUrl::fromLocalFile(m_rs_path.c_str()));

	m_player->play();
}

} // namespace tt