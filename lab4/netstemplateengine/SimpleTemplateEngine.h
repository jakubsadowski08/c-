
#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>



namespace nets
{
    class View
    {
        std::string text;
        //std::unordered_map <std::string, std::string> model;
    public:
        View(std::string napis);
        std::string Render(const std::unordered_map <std::string, std::string> &model) const;
    };

}
#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
