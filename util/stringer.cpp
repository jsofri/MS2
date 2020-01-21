//
// Created by yehonatan on 12/01/2020.
//

#include "stringer.h"

using namespace std;


string Stringer::lineFromCharArray(char* array) {
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

list<string> Stringer::stringListFromCharArray(char * array) {
  list<string> list;
  int i = 0, j;
  char notTerminate;

  //holds end of each line - might be '\n' or '\0'
  notTerminate = array[i];

  //iterate on all array
  for (; notTerminate; i++) {
    string str = "";

    //iterate on one line
    for (;array[i] != '\n' && array[i] != '\0'; i++) {
      str += array[i];
    }

    notTerminate = array[i];

    if (str != "") {
      list.push_back(str);
    }
  }

  return list;
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

//get a list of string with unordered lines
//return a list where each string is a line
list<string> Stringer::listOfLines(list<string> input) {
  list<string> output;
  string tmp;
  int i;

  for (auto str : input) {
    for (i = 0; i < str.size(); i++) {
      if (str[i] != '\n') {
        tmp += str[i];
      } else {
        output.push_back(tmp);
        tmp = "";
      }
    }
  }

  return output;
}

//get a string and return a point
Point Stringer::pointFromString(string str) {
  vector<string> coordinates = doRegex(str, REGEX);
  int i, j;

  i = stoi(coordinates[0]);
  j = stoi(coordinates[1]);

  return Point(i,j);
}