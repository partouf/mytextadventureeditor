#pragma once

#include "../stdafx.h"

namespace StrUtils
{
   template <class T>
   std::vector<T> split(const T &input, const T &rex) {
      std::vector<T> items;

      std::regex re(rex);
      std::sregex_token_iterator regiter(input.begin(), input.end(), re, -1);
      std::sregex_token_iterator regend;

      while (regiter != regend)
      {
         items.emplace_back(*regiter++);
      }

      return items;
   }

}
