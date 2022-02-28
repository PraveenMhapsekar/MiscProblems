using namespace std;
#include <string.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

vector<vector<string>> 
groupAnagrams(vector<string> &strs) {
	unordered_map<string, vector<string>> mp;
	vector<vector<string>> ans;

	for (int i = 0; i < strs.size(); i++) {
		string ff = strs[i];
    // sort string
		sort(ff.begin(), ff.end());
    // store sorted string in unordered map aka hash
		mp[ff].push_back(strs[i]);
	}

	unordered_map<string,vector<string>>::iterator itr;
	for (itr = mp.begin(); itr != mp.end(); itr++) {
		ans.push_back(itr->second);
	}

	return ans;
}

int 
main() 
{
  vector<string> vec = {"star", "tars", "rats", "cats", "flats", "stafl", "cast"};
  vector<vector<string>> result;

  cout << endl << "printing inputs: " << endl;
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  result = groupAnagrams(vec);

  cout << endl << "printing solutions: " << endl;
  for (std::vector<vector<string>>::iterator i = result.begin(); i != result.end(); i++) {
    vector<string> pVec = *i;
    vector<string> ::iterator itr;
    for (itr = pVec.begin(); itr != pVec.end(); itr++) {
      cout << *itr << " ";
    }
    cout << endl;
  }
   
  return 0;
}
