#include "SelectLabel.h"
#include <qpushbutton.h>
#include <QFileDialog>
#include <QMessageBox>


namespace tt {

tt::SelectLabel::SelectLabel(QWidget* parent)
{
	setParent(parent);
	m_lp = GetPoint<LogPanel>();
	m_btn_select = new QPushButton(this);
	m_btn_select->setText("select");

	m_lbl_cur_dir = new QLabel(this);
	m_lbl_cur_dir->setText("cur_dir: no select");

	this->resize(600, 20);
	m_btn_select->setGeometry(550, 0, 50, 20);
	m_lbl_cur_dir->setGeometry(0, 0, 540, 20);

	connect(m_btn_select, &QPushButton::clicked,
		this, &SelectLabel::on_btn_select_clicked);

}

tt::SelectLabel::~SelectLabel()
{

}

void SelectLabel::set_cur_dir(const std::string& cur_dir) { 
	m_cur_dir = cur_dir; 
	m_lbl_cur_dir->setText((std::string("cur_dir: ") + cur_dir).c_str());
}

void SelectLabel::on_btn_select_clicked() {
	L_DEBUG + "btn_select clicked!\n";
	QString fileName = QFileDialog::getExistingDirectory(
		//this,
		nullptr,
		tr("open a file."),
		"E:\\resource\\videoplay\\videos\\"
		//tr("All files(*.*);;images(*.png *jpeg *bmp);;video files(*.avi *.mp4 *.wmv)")
		);
	if (fileName.isEmpty()) {
		QMessageBox::warning(this, "Warning!", "Failed to open the directory!");
		return;
	}
	if (std::filesystem::directory_entry(fileName.toStdString()).status().type() !=
		std::filesystem::file_type::directory) {
		QMessageBox::warning(this, "Error!", "Failed to open the directory!");
		return;
	}
	set_cur_dir(fileName.toStdString());

}


}



