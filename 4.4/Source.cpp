#include <fstream>
#include <string>

using namespace std;

int amount();					//пошук кількості рядків
void find_worlds(int*& w, int n);		//пошук кількості слів у рядках
void find_signs(int*& s, int n);			//пошук кількості знаків у рядках
bool check(char ch);			//перевірка на знак
void resolve(int* w, int* s, int n);	//копіювання у файл 2


int main() {
	int n = amount();
	int* w = new int[n];
	int* s = new int[n];
	find_worlds(w, n);
	find_signs(s, n);
	resolve(w, s, n);
}

int amount() {
	fstream f("file.txt");
	int k = 1;
	char ch;
	while (!f.eof()) {
		f.get(ch);
		if (ch == '\n') {
			k++;
		}
	}
	return k;
}
void find_worlds(int*& w, int n) {
	fstream f("file.txt");
	for (int i = 0; i < n; i++) {
		w[i] = 1;
		char ch = 'w';
		while (ch != '\n' && !f.eof()) {
			f.get(ch);
			if (ch == ' ') {
				w[i]++;
			}
		}

	}
}
void find_signs(int*& s, int n) {
	fstream f("file.txt");
	for (int i = 0; i < n; i++) {
		s[i] = 0;
		char ch = 'w';
		while (ch != '\n' && !f.eof()) {
			f.get(ch);
			if (check(ch)) {
				s[i]++;
			}
		}

	}
}
bool check(char ch) {
	if (ch == ',' || ch == '.' || ch == '?' || ch == '!' || ch == '-' || ch == '\'' || ch == '\"' || ch == '(' || ch == ')') {
		return true;
	}
	else {
		return false;
	}
}

void resolve(int* w, int* s, int n) {
	fstream f1("file.txt", ios::in);
	fstream f2("file2.txt", ios::out);
	string t;

	for (int i = 0; i < n; i++) {
		f2 << w[i];
		for (int j = 0; j < w[i]; j++) {
			f1 >> t;
			f2 << t << ' ';
		}
		f2 << s[i] << endl;
	}
}
