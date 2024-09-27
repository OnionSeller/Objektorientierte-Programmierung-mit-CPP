#include <iostream>
#include <vector>
#include <limits>  // Für std::numeric_limits

using namespace std;

double max(const vector<double>& v) {

    if (v.empty()) {
        throw invalid_argument("Der Vektor ist leer.");
    }
    
    double maxVal = -numeric_limits<double>::infinity();
    for (double val : v) {
        if (val > maxVal) {
            maxVal = val;
        }
    }
    return maxVal;
}

bool allPositive(const vector<double>& v) {
    for (double val : v) {
        if (val <= 0) {
            return false;
        }
    }
    return true;
}

// Skalarprodukt
double product(const vector<double>& v1, const vector<double>& v2) {
    if (v1.size() != v2.size()) {
        throw invalid_argument("Die Vektoren haben unterschiedliche Größen.");
    }

    double result = 0.0;
    for (size_t i = 0; i < v1.size(); ++i) {
        result += v1[i] * v2[i];
    }
    return result;
}

// Das Produkt eines Vektors mit einer Zahl berechnen
vector<double> product(const vector<double>& v, double f) {
    vector<double> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[i] * f;
    }
    return result;
}

// Die Norm berechnet
double norm(const vector<double>& v) {
    double sum = 0.0;
    for (double val : v) {
        sum += val * val;
    }
    return sqrt(sum);
}

// Vektor normalisieren (in-place)
void normalize(vector<double>& v) {
    double vectorNorm = norm(v);
    if (vectorNorm == 0) {
        throw invalid_argument("Die Norm des Vektors ist 0. Der Vektor kann nicht normalisiert werden.");
    }

    for (double& val : v) {
        val /= vectorNorm;
    }
}

// Hauptprogramm
int main() {
    int n;
    cout << "Geben Sie die Größe des Vektors ein: ";
    cin >> n;

    vector<double> v1(n), v2(n);
    cout << "Geben Sie die Elemente des ersten Vektors in eine Zeile ein:\n";
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }

    cout << "Geben Sie die Elemente des zweiten Vektors in eine Zeile ein:\n";
    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
    }

    try {
        // Testen der max-Funktion
        cout << "Größter Wert im ersten Vektor: " << max(v1) << endl;
        cout << "Größter Wert im zweiten Vektor: " << max(v2) << endl;

        // Testen der allPositive-Funktion
        cout << "Alle Werte im ersten Vektor sind positiv: " << (allPositive(v1) ? "Ja" : "Nein") << endl;
        cout << "Alle Werte im zweiten Vektor sind positiv: " << (allPositive(v2) ? "Ja" : "Nein") << endl;

        // Testen der product-Funktion (Skalarprodukt)
        cout << "Skalarprodukt der beiden Vektoren: " << product(v1, v2) << endl;

        // Testen der product-Funktion
        double scalar;
        cout << "Geben Sie einen Skalarwert ein: ";
        cin >> scalar;
        vector<double> vProduct = product(v1, scalar);
        cout << "Produkt des ersten Vektors mit dem Skalar: ";
        for (double val : vProduct) {
            cout << val << " ";
        }
        cout << endl;

        vProduct = product(v2, scalar);
        cout << "Produkt des zweiten Vektors mit dem Skalar: ";
        for (double val : vProduct) {
            cout << val << " ";
        }
        cout << endl;

        // Testen der norm-Funktion
        cout << "Norm des ersten Vektors: " << norm(v1) << endl;
        cout << "Norm des zweiten Vektors: " << norm(v2) << endl;

        // Testen der normalize-Funktion
        normalize(v1);
        cout << "Normalisierter erster Vektor: ";
        for (double val : v1) {
            cout << val << " ";
        }
        cout << endl;

        normalize(v2);
        cout << "Normalisierter zweiter Vektor: ";
        for (double val : v2) {
            cout << val << " ";
        }
        cout << endl;

    }
    catch (const exception& e) {
        cout << "Fehler: " << e.what() << endl; // throw invalid_argument
    }

    system("pause");
    return 0;
}
