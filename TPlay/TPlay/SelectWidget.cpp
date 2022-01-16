#include "SelectWidget.h"
#include "TPlay.h"
namespace tt {
SelectWidget::SelectWidget(QWidget* parent)
{
	set_parent(parent);
	bind_func();
}
	void SelectWidget::bind_func()
{
	connect(this, &SelectWidget::itemDoubleClicked, 
		this, &SelectWidget::on_double_click_item);

	m_lp = GetPoint<LogPanel>();
	

}


void SelectWidget::add_item_from_file(const std::string& path)
{
	std::map<int, std::string> rs;
	FileSearcher::Search(m_rs, path, "*.mp4");
	m_rootDir = path;
	int row = 0;
	for (auto& it : m_rs) {
		this->addItem(it.second.c_str());
		
	}
}
int FileSearcher::IsMatch(const std::string& str, const std::string& ruler)
{
	int n = 0;
	int is_star = 0;
	for (auto& cr : ruler) {
		if (is_star) {
			n = str.find_first_of(cr, n);
			if (n == std::string::npos) { return 0; }
			n++;
			continue;
		}
		if (cr == '*') {
			is_star = 1;
			continue;
		}
		if (cr == '_') {
			n++;
			continue;
		}
		if (cr != str[n]) {
			return 0;
		}
		n++;
	}
	if (n == str.size())
		return 1;
	else
		return 0;
}
std::string FileSearcher::Search(std::map<int, std::string>& rt, const std::string& rootDir, std::string ruler, int(*cmp)(const std::string& st1, const std::string& st2))
{

	// get path
	std::filesystem::path dirPath(rootDir);
	if (!exists(dirPath)) {
		return "error root_dir";
	}

	// path type
	std::filesystem::directory_entry de(dirPath);
	if (de.status().type() != std::filesystem::file_type::directory) {
		return "root path is not a dir!";
	}


	// get files
	std::stringstream ss;
	std::filesystem::directory_iterator di(dirPath);
	int row = 0;
	std::string fn = "";
	for (auto& it : di) {
		fn = it.path().filename().string();
		if (IsMatch(fn, ruler))
			rt.insert(std::pair<int, std::string>(row++, fn));
	}
	return "Search success";
}

void tt::SelectWidget::on_double_click_item() {
	m_cur_row = currentRow();
	m_cur_rs_path = m_rootDir + m_rs[m_cur_row];

	L_DEBUG + "one item double clicked! \n";
	L_DEBUG + "current item : " + currentRow() + "\n";
	L_DEBUG + "current rs_path: " + m_cur_rs_path + "\n";
	
	((TPlay*)parent())->play(m_cur_rs_path);
}



TListWidget::TListWidget()
{
	m_lp = GetPoint<LogPanel>();
	L_DEBUG + "TListWidget used";
}


TListWidget::~TListWidget()
{
}

void TListWidget::tAddItem()
{
	
}

} // namespace tt
