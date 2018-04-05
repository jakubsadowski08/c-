#include"SimpleTemplateEngine.h"

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' conains 'from', like replacing 'x' with 'yx'
    }
}
nets::View::View(std::string napis)
{
    text = napis;
}
nets::View::Render(const std::unordered_map <std::string, std::string> &model) const
{

    auto i = model.end();
}