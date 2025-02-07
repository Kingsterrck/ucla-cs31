#include <iostream>
#include <cctype>
#include <cassert>
using namespace std;

bool isValidQC(string results) {
	if (results.empty()) { // empty string check
		return false;
	}
	while (!results.empty()) {
		if (results[0] == 'Q') { // check leading Q
			results = results.substr(1,results.size()-1); // remove Q
			int total = 0;
			while (isdigit(results[0])) { // collect Q digits
				total *= 10;
				total += std::stoi(results.substr(0,1)); // convert the first digit into integer
				if (total == 0 && results[0] == '0' && isdigit(results[1])) {
					return false;
				}
				results = results.substr(1,results.size()-1);
			}
			if (total == 0) { // batch cannot be 0
				return false;
			}
			int p = 0; // initialize counters
			int d = 0;
			bool flag1 = true;
			bool flag2 = true;
			if (results[0] == 'p') { // case where starting with P
				results = results.substr(1,results.size()-1);
				while (isdigit(results[0])) {
					flag1 = false; // check that there is at least one digit
					p *= 10;
					p += std::stoi(results.substr(0,1));
					if (p == 0 && results[0] == '0' && isdigit(results[1])) {
						return false;
					}
					results = results.substr(1,results.size()-1);
				}
				if (results[0] == 'd') { // start collecting D
					results = results.substr(1,results.size()-1);
					while (isdigit(results[0])) {
						flag2 = false;
						d *= 10;
						d += std::stoi(results.substr(0,1));
						if (d == 0 && results[0] == '0' && isdigit(results[1])) {
							return false;
						}
						results = results.substr(1,results.size()-1);
					}
				} else {
					return false;
				}

			} else if (results[0] == 'd') { // case where starting with D
				results = results.substr(1,results.size()-1);
				while (isdigit(results[0])) {
					flag1 = false;
					d *= 10;
					d += std::stoi(results.substr(0,1));

					if (d == 0 && results[0] == '0' && isdigit(results[1])) {
						return false;
					}
					results = results.substr(1,results.size()-1);
				}
				if (results[0] == 'p') { // start collecting P
					results = results.substr(1,results.size()-1);
					while (isdigit(results[0])) {
						flag2 = false;
						p *= 10;
						p += std::stoi(results.substr(0,1));

						if (p == 0 && results[0] == '0' && isdigit(results[1])) {
							return false;
						}
						results = results.substr(1,results.size()-1);
					}
				} else {
					return false;
				}
			} else {
				return false;
			}
			if (p + d != total || flag1 || flag2) { // pass and defect results must equal the total number of tests
				return false;
			}
		} else {
			return false;
		}
	}
	return true;
}

int passQC(string results) {
	if (isValidQC(results)) { // validate string
		int count = 0;
		while (!results.empty()) {
			if (results[0] == 'p') {
				int temp = 0;
				results = results.substr(1, results.size()-1);
				while (isdigit(results[0])) {
					temp *= 10;
					temp += std::stoi(results.substr(0,1));
					results = results.substr(1,results.size()-1);
				}
				count += temp;
			} else {
				results = results.substr(1, results.size()-1);
			}
		}
		return count;
	} else {
		return -1;
	}
}

int defectQC(string results) {
	if (isValidQC(results)) {
		int count = 0;
		while (!results.empty()) {
			if (results[0] == 'd') {
				int temp = 0;
				results = results.substr(1, results.size()-1);
				while (isdigit(results[0])) {
					temp *= 10;
					temp += std::stoi(results.substr(0,1));
					results = results.substr(1,results.size()-1);
				}
				count += temp;
			} else {
				results = results.substr(1, results.size()-1);
			}
		}
		return count;
	} else {
		return -1;
	}
}

int totalQC(string results) {
	if (isValidQC(results)) {
		int count = 0;
		while (!results.empty()) {
			if (results[0] == 'Q') {
				int temp = 0;
				results = results.substr(1, results.size()-1);
				while (isdigit(results[0])) {
					temp *= 10;
					temp += std::stoi(results.substr(0,1));
					results = results.substr(1,results.size()-1);
				}
				count += temp;
			} else {
				results = results.substr(1, results.size()-1);
			}
		}
		return count;
	} else {
		return -1;
	}
}

int batches(string results) {
	if (isValidQC(results)) {
		int count = 0;
		for (char c : results) {
			if (c == 'Q') {
				count++;
			}
		}
		return count;
	} else {
		return -1;
	}
}

int main() {
	// testing isValidQC()
	// valid cases
	assert(isValidQC("Q2p1d1") == true); // basic case
	assert(isValidQC("Q2d1p1Q5p3d2") == true); // multiple batches
	assert(isValidQC("Q1p0d1Q1d0p1") == true); // multiple bathes with 0
	assert(isValidQC("Q5d2p3") == true); // basic case
	assert(isValidQC("Q10d10p0Q10d0p10") == true); // multiple batches with multiple digits and 0
	assert(isValidQC("Q845d551p294") == true); // multiple digits
	assert(isValidQC("Q916d357p559Q900p481d419Q516p434d82Q589d163p426") == true); // multiple digits

	// invalid cases
	assert(isValidQC("q1p0d1") == false); // batch must be reported with Q
	assert(isValidQC("Q1pd1") == false); // a number for pass is required
	assert(isValidQC("Q1p1d") == false); // a number for defect is required
	assert(isValidQC("Q1p0d1 asdfR") == false); // extra characters not allowed
	assert(isValidQC("Q5p00003d0002") == false); // leading zeros not allowed
	assert(isValidQC("Q5p0d0") == false); // pass and defect results must equal the total number of tests
	assert(isValidQC("Q0p0d0") == false); // batch cannot be zero

	// more invalid cases
	assert(isValidQC("1p1d") == false); // leading Q is required
	assert(isValidQC("Q2p") == false); // d is required
	assert(isValidQC("Q2x3d") == false); // no other characters
	assert(isValidQC("") == false); // no empty strings
	assert(isValidQC("Q-1p1d-2") == false); // no negative numbers

	// testing passQC()
	assert(passQC("Q6d2p4") == 4); // single batch
	assert(passQC("Q5d5p0") == 0); // single batch with 0
	assert(passQC("Q7p5d2Q3p1d2") == 6); // multiple batches
	assert(passQC("Q99p66d33") == 66); // multiple digits

	// testing defectQC()
	assert(defectQC("Q6d2p4") == 2); // single batch
	assert(defectQC("Q5d0p5") == 0); // single batch with 0
	assert(defectQC("Q7p5d2Q3p1d2") == 4); // multiple batches
	assert(defectQC("Q99p66d33") == 33); // multiple digits

	// testing totalQC()
	assert(totalQC("Q6d2p4") == 6); // single batch
	assert(totalQC("Q5d5p0") == 5); // single batch with 0
	assert(totalQC("Q7p5d2Q3p1d2") == 10); // multiple batches
	assert(totalQC("Q99p66d33") == 99); // multiple digits

	// testing batches()
	assert(batches("Q6d2p4") == 1); // single batch
	assert(batches("Q7p5d2Q3p1d2") == 2); // two batches
	assert(batches("Q6d2p4Q6d2p4Q6d2p4Q6d2p4Q6d2p4Q6d2p4Q6d2p4Q6d2p4Q6d2p4Q6d2p4") == 10); // many...batches

	return 0;
}