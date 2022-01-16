#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>

#include <list>
#include <string>
#include <map>
#include <filesystem>
#include <sstream>

#include "LogPanel.h"

namespace tt {

class FileSearcher {
public:
	FileSearcher() { }
	~FileSearcher() { }
	static int IsMatch(const std::string& str, const std::string& ruler);

	static std::string Search(std::map<int, std::string>& rt,
		const std::string& rootDir,
		std::string ruler,
		int (*cmp)(const std::string& st1, const std::string& st2) = nullptr);
private:

}; // class FileSearcher




class TListWidget : protected QListWidget{
public:
	TListWidget();
	~TListWidget();

	void tAddItem();
	LogPanel& lp() { return *m_lp; }

private:
	LogPanel *m_lp;
};
class SelectWidget : public QListWidget
{
public:
	SelectWidget(QWidget* parent = nullptr);
	~SelectWidget() { }
	
	void bind_func();
	void set_parent(QWidget* parent = nullptr) { this->setParent(parent); }

	void add_item_from_file(const std::string& path);
	int  current_row() { return currentRow(); }

	int  rs_count() const { return m_rsCount; }
	void mark_row() {}

	LogPanel& lp() { return *m_lp; }

	const std::string& rs_path() const { return m_cur_rs_path; }
	const uint32_t& cur_row() const { return m_cur_row; }

public slots:
	void on_double_click_item();
	void onItemChanged() { }
private:
	std::map<int, std::string>   m_rs;
	int							 m_rsCount;
	std::string					 m_rootDir;
	QPushButton					 m_btn_select;

	std::string					m_cur_rs_path;
	uint32_t					m_cur_row;

	LogPanel* m_lp;
}; // class SelectWidget

} // namespace tt


