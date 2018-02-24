
#include "split.h"

std::vector<std::string> str::split(const std::string &input, const std::string &rex) {
   std::vector<std::string> items;

   std::regex re(rex);
   std::sregex_token_iterator regiter(input.begin(), input.end(), re, -1);
   std::sregex_token_iterator regend;

   while (regiter != regend)
   {
      items.emplace_back(*regiter++);
   }

   return items;
}
