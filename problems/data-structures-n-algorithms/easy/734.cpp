// 734. Sentence Similarity
// https://leetcode.com/problems/sentence-similarity/

#include <bits/stdc++.h>
#include <deque>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

bool areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2,
												 vector<vector<string>> &similarPairs) {
	unordered_set<string> lset;
	unordered_set<string> rset;

	for (int i = 0; i < similarPairs.size(); i++) {
		lset.insert(similarPairs[i][0]);
		rset.insert(similarPairs[i][1]);
	}

	bool isSimilar = true;
	int i = 0;
	while (i < sentence1.size() && i < sentence2.size()) {
		if (sentence1[i] == sentence2[i]) {
			i++;
			continue;
		}

		auto iter1 = lset.find(sentence1[i]);
		auto iter2 = rset.find(sentence2[i]);
		if (iter1 != lset.end() && iter2 != rset.end()) {
			i++;
			continue;
		}

		auto iter3 = lset.find(sentence2[i]);
		auto iter4 = rset.find(sentence1[i]);
		if (iter3 != lset.end() && iter4 != rset.end()) {
			i++;
			continue;
		}

		isSimilar = false;
		break;
	}

	if (isSimilar == true && sentence1.size() == sentence2.size()) {
		return true;
	}
	return false;
}

int main() {
	//

	vector<string> sentence1;
	vector<string> sentence2;
	vector<vector<string>> similarPairs;

	// sentence1 = {"an", "extraordinary", "meal"};
	// sentence2 = {"one", "good", "dinner"};
	// similarPairs = {{"great", "good"},		 {"extraordinary", "good"},
	// 								{"well", "good"},			 {"wonderful", "good"},
	// 								{"excellent", "good"}, {"fine", "good"},
	// 								{"nice", "good"},			 {"any", "one"},
	// 								{"some", "one"},			 {"unique", "one"},
	// 								{"the", "one"},				 {"an", "one"},
	// 								{"single", "one"},		 {"a", "one"},
	// 								{"truck", "car"},			 {"wagon", "car"},
	// 								{"automobile", "car"}, {"auto", "car"},
	// 								{"vehicle", "car"},		 {"entertain", "have"},
	// 								{"drink", "have"},		 {"eat", "have"},
	// 								{"take", "have"},			 {"fruits", "meal"},
	// 								{"brunch", "meal"},		 {"breakfast", "meal"},
	// 								{"food", "meal"},			 {"dinner", "meal"},
	// 								{"super", "meal"},		 {"lunch", "meal"},
	// 								{"possess", "own"},		 {"keep", "own"},
	// 								{"have", "own"},			 {"extremely", "very"},
	// 								{"actually", "very"},	{"really", "very"},
	// 								{"super", "very"}};

	sentence1 = {"one", "excellent", "meal"};
	sentence2 = {"one", "good", "dinner"};
	similarPairs = {{"great", "good"},		 {"extraordinary", "good"},
									{"well", "good"},			 {"wonderful", "good"},
									{"excellent", "good"}, {"fine", "good"},
									{"nice", "good"},			 {"any", "one"},
									{"some", "one"},			 {"unique", "one"},
									{"the", "one"},				 {"an", "one"},
									{"single", "one"},		 {"a", "one"},
									{"truck", "car"},			 {"wagon", "car"},
									{"automobile", "car"}, {"auto", "car"},
									{"vehicle", "car"},		 {"entertain", "have"},
									{"drink", "have"},		 {"eat", "have"},
									{"take", "have"},			 {"fruits", "meal"},
									{"brunch", "meal"},		 {"breakfast", "meal"},
									{"food", "meal"},			 {"dinner", "meal"},
									{"super", "meal"},		 {"lunch", "meal"},
									{"possess", "own"},		 {"keep", "own"},
									{"have", "own"},			 {"extremely", "very"},
									{"actually", "very"},	{"really", "very"},
									{"super", "very"}};

	bool res = areSentencesSimilar(sentence1, sentence2, similarPairs);

	cout << res << endl;

	return 0;
}