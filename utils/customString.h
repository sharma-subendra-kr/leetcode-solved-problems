vector<string> split(string str, char c) {
	vector<string> res;
	string temp;
	stringstream _str(str);
	while (getline(_str, temp, c)) {
		res.push_back(temp);
	}

	return res;
}