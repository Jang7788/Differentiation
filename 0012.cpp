#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string fc, result = "";
    cin >> fc;

    if (fc[0] != '-' && fc[0] != '+') {
        fc = "+" + fc;
    }

    vector<pair<int, int>> differentiated_terms; 
    int start_pos = 0;

    while (start_pos < fc.size()) {
        int end_pos = fc.find_first_of("+-", start_pos + 1);
        if (end_pos == string::npos) {
            end_pos = fc.size(); 
        }

        string term = fc.substr(start_pos, end_pos - start_pos);
        start_pos = end_pos;
        int coeff = 0, exp = 0;
        size_t x_pos = term.find('x');
        size_t caret_pos = term.find('^');

        if (x_pos == string::npos) {
            coeff = stoi(term);
            exp = 0;
        } else {
            string coeff_str = term.substr(0, x_pos);
            if (coeff_str == "+") coeff = 1;
            else if (coeff_str == "-") coeff = -1;
            else coeff = stoi(coeff_str);

            if (caret_pos == string::npos) {
                exp = 1;
            } else {
                string exp_str = term.substr(caret_pos + 1);
                exp = stoi(exp_str);
            }
        }

        int new_coeff = coeff * exp;
        int new_exp = (exp > 0) ? exp - 1 : 0;

        if (new_coeff != 0) {
            differentiated_terms.push_back({new_coeff, new_exp});
        }
    }

    for (int i = 0; i < differentiated_terms.size(); ++i) {
        int c = differentiated_terms[i].first; 
        int e = differentiated_terms[i].second; 
        int abs_c = abs(c);

        if (i == 0) {
            if (c < 0) result += "-";
        } else {
            result += (c > 0) ? "+" : "-";
        }

        if (abs_c != 1 || e == 0) {
            result += to_string(abs_c);
        }

        if (e == 1) {
            result += "x"; 
        } else if (e > 1) {
            result += "x^" + to_string(e);
        }
    }

    if (result.empty()) {
        cout << "0";
    } else {
        cout << result;
    }

    return 0;
}