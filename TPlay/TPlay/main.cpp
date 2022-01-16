#include "TPlay.h"

#include <QApplication>
#include <QFile>
#include "LogPanel.h"
#include "SelectWidget.h"
#include "PlayerController.h"

#define DEBUG_OUT LOG_DEBUG(pc.lp())
#define ERROR_OUT LOG_ERROR(pc.lp())
#define INFO_OUT  LOG_INFO(pc.lp()) 

using namespace tt;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    tt::PlayerController pc;
    pc.show();

    
    INFO_OUT + "hello LogPanel!" + "\n";
    
    return a.exec();
}

