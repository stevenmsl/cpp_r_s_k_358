#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol358;

string toString(vector<int> input)
{
  string result = "[";
  for (auto e : input)
  {
    result += to_string(e);
    result += ",";
  }
  /* remove the last comma */
  if (result.size() > 1)
    result.pop_back();
  result += "]";
  return result;
}

/*
Input: s = "aabbcc", k = 3
Output: "abcabc"
Explanation: The same letters are at least distance 3 from each other.
*/
tuple<string, int, string> testFixture1()
{
  return make_tuple("aabbcc", 3, "abcabc");
}

/*
Input: s = "aaabc", k = 3
Output: ""
Explanation: It is not possible to rearrange the string.
*/
tuple<string, int, string> testFixture2()
{
  return make_tuple("aaabc", 3, "");
}

/*
Input: s = "aaadbbcc", k = 2
Output: "abacabcd"
Explanation: The same letters are at least distance 2 from each other.
*/
tuple<string, int, string> testFixture3()
{
  return make_tuple("aaadbbcc", 2, "abacabcd");
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see (posible result) " << get<2>(f) << endl;
  auto result = Solution::rearrange(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see (posible result) " << get<2>(f) << endl;
  auto result = Solution::rearrange(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see (posible result) " << get<2>(f) << endl;
  auto result = Solution::rearrange(get<0>(f), get<1>(f));
  cout << "result: " << result << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}