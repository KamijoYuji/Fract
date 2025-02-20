#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Fract {
	double a;
	double b;
	double value = 0.0;
public:
	void reduct(double eps = 0.00001) {
		if (!a and b) {
			b = 1;
			value = 0.0;
		}

		if (!b)
			return;

		while (!(abs(floor((a+0.5)) - a) < eps and abs(floor((b + 0.5)) - b) < eps)) {
			a *= 10; b *= 10;
		}

		int c = a < b ? a : b;
		while (c) {
			if (!(int(float(a)) % c) and !(int(float(b)) % c))
			{
				a /= double(c);
				b /= double(c);
			}
			c--;
		}

	}

	Fract() { a = 0.0; b = 1.0; value = 0.0; }
	Fract(double n, double m) { a = n; b = m; if(b)value = a / b; }
	Fract(int n, double m) { a = double(n); b = m; if (b)value = a / b; }
	Fract(double n, int m) { a = n; b = double(m); if (b)value = a / b; }
	Fract(int n, int m) { a = double(n); b = double(m); if (b)value = a / b; }
	Fract(double val) { value = val; a = val; b = 1.0; reduct(); }
	Fract(int val) { value = double(val); a = double(val); b = 1.0; reduct(); }

	friend ostream& operator << (ostream& out, Fract& other) {
		if (!other.b)
			out << "ERROR";
		else
			if (other.b == 1)
				out << other.a;
			else
				if (!other.a)
				out << "0";
				else
					out << other.a << "/" << other.b;
		return out;
	}

		string getVal() {return (b ? to_string(value) : "ERROR"); }

		Fract operator + (Fract& other) {
			Fract c = Fract(a * other.b + other.a * b, b * other.b);
			c.reduct();
			return c;
		}

		Fract operator - (Fract& other) {
			Fract c = Fract(a * other.b - other.a * b, b * other.b);
			c.reduct();
			return c;
		}

		Fract operator * (Fract& other) {
			Fract c = Fract(a * other.a, b * other.b);
			c.reduct();
			return c;
		}

		Fract operator / (Fract& other) {
			Fract c = Fract(a * other.b, b * other.a);
			c.reduct();
			return c;
		}
};

int main() {
	Fract a(0.105);
	cout << a;
	return 0;
}
