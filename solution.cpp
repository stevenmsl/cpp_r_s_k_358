#include "solution.h"
#include "util.h"
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <string>
#include <queue>
using namespace sol358;
using namespace std;

/*takeaways
  - build a sequence consisting of k different
    characters
    - the characters need to be sorted in the
      queue if they have the same frequency
      - to maintain the k distance rule
        among sequences
      - let say you built "ca" and ready to
        build the next sequence. In the queue,
        if c and a have the same frequency, you
        want to pick c not a!
    - start with the highest frequency char
      when building a sequence
  - use a max-heap based on the frequency first
    and then char order to help building the
    sequences
*/

string Solution::rearrange(string input, int k)
{
  auto s = string("");

  auto freq = unordered_map<char, int>();
  for (auto c : input)
    freq[c]++;

  /*max-heap by char's frequency
    - we use a pair here so if will
      first sort by frequency then
      the character
      - the order of the chars is
        maintained among them if
        they have the same frequency
      - that means while building
        the k-length sequences we
        pick up different characters
        by descedning order(max-Heap)
  */
  auto topFreq = priority_queue<pair<int, char>>();
  for (auto i = freq.begin(); i != freq.end(); i++)
    topFreq.push({(*i).second, (*i).first});

  /*
    - track the number of remaining characters
  */
  int len = input.size();
  while (!topFreq.empty())
  {
    /*
      - keep track of what have been popped out
        for building the sequence
      - we need to put them back in a batch
        later so won't pick the same char again
        if it has a very high frequncey!
    */
    auto batch = vector<pair<int, char>>();
    /*
      - to deal with when it's fewer than
        k characters left
    */
    auto seqLen = min(len, k);
    /*
      - build a sequence of length "seqLen"
        using different characters
      - don't put the char right back to
        the queue as you might pick it again
        if it has a very high frequency!
    */
    for (auto i = 0; i < seqLen; i++)
    {
      /*
        - not enough different chars
          to build a sequence
      */
      if (topFreq.empty())
        return "";
      auto f = topFreq.top();
      topFreq.pop();
      s.push_back(f.second);
      /*
        - still have leftover;
        - need to put it back
          to the queue later
      */
      if (--f.first > 0)
        batch.push_back(f);
      --len;
    }
    /* push them back in a batch! */
    for (auto a : batch)
      topFreq.push(a);
  }

  return s;
}
