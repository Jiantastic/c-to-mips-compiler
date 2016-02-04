/*
 *
 * Copyright (c) 1998-2002
 * John Maddock
 *
 * Use, modification and distribution are subject to the 
 * Boost Software License, Version 1.0. (See accompanying file 
 * LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /*
  *   LOCATION:    see http://www.boost.org for most recent version.
  *   FILE         credit_card_example.cpp
  *   VERSION      see <boost/version.hpp>
  *   DESCRIPTION: Credit card number formatting code.
  */

#include <string>
#include <boost/regex.hpp>

// the following function checks if a credit card number is formatted properly
// (that is: 16 digits in groups of four separated by either a dash or a space)
bool validate_card_format(const std::string& s)
{
   static const boost::regex e("(\\d{4}[- ]){3}\\d{4}");
   // \d means 'any digit', {4} means 'repeated exactly four times'
   // (see also regex references e.g. on rubular)
   return boost::regex_match(s, e);
   // regex_match tries to match string and regex
   // returns false if no match is possible (not a valid format)
}

const boost::regex e("\\A(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})\\z");
const std::string machine_format("\\1\\2\\3\\4");
const std::string human_format("\\1-\\2-\\3-\\4");

// the two following functions don't just perform a check...

std::string machine_readable_card_number(const std::string& s)
{
   return boost::regex_replace(s, e, machine_format, boost::match_default | boost::format_sed);
}

   // regex_replace returns a string obtained as follows:
   
   // regex e (again a regex for a credit card number
   // but this time the format is different, can you see why?)
   // is matched against string s
   
   // when the match takes place, special 'regex variables' are assigned, 
   // (not just in boost but also in other regex systems) 
   // one for each group being matched; these variables are \1, \2 etc
   
   // for example: if the cc number is 0000-1111-2222-3333
   // the initial (\\d{4})[- ]? will match with 0000-
   // and \1 will contain 0000 
   // NB: variables contain what is in (), the [- ] is outside
   
   // the string is then replaced according to the
   // machine_format string:
   // in this case all the groups of 4 digits 
   // (one in each regex variable from \1 to \4)
   // are just written glued together)
   
   
   
// in the following function, instead,
// the groups of 4 digits are separated by a dash 
// (see human_format string above)

std::string human_readable_card_number(const std::string& s)
{
   return boost::regex_replace(s, e, human_format, boost::match_default | boost::format_sed);
}

#include <iostream>
using namespace std;

int main()
{
   string s[4] = { "0000111122223333", "0000 1111 2222 3333",
                   "0000-1111-2222-3333", "000-1111-2222-3333", };
   int i;
   for(i = 0; i < 4; ++i)
   {
      cout << "validate_card_format(\"" << s[i] << "\") returned " << validate_card_format(s[i]) << endl;
   }
   for(i = 0; i < 4; ++i)
   {
      cout << "machine_readable_card_number(\"" << s[i] << "\") returned " << machine_readable_card_number(s[i]) << endl;
   }
   for(i = 0; i < 4; ++i)
   {
      cout << "human_readable_card_number(\"" << s[i] << "\") returned " << human_readable_card_number(s[i]) << endl;
   }
   
// notice that strings not matching the regex
// (for instance in this case ?)
// are kept without changes
   
   return 0;
}


