//
// Created by yehonatan on 12/01/2020.
//

#include "stringer.h"

using namespace std;


string Stringer::stringFromCharArray(char* array) {
    string result = "";
    int i = 0;

    while (array[i] != '\0') {
        if (array[i] == '\n' || array[i] == '\r') {
            break;
        }
        result += array[i];
        i++;
    }

    return result;
}


/**
 * get matches from string using regex
 * @param str a single line
 * @param pattern the pattern
 * @return a vector of matches
 */
vector<string> Stringer :: doRegex(string str, string pattern) {
  vector<string> matches;

  auto reg = regex(pattern);
  auto iter = sregex_iterator(str.begin(), str.end(), reg);
  auto iterHelper = sregex_iterator();

  // loop the matches
  for (auto i = iter; i != iterHelper; ++i) {

      // skip empty matches
      if (((*i).str()) == "") {
        continue;
      }

      matches.push_back((*i).str());
    }

  return matches;
}