#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Fract {
	double a;
	double b;
	double value = 0.0;
public:
	static int gcd(int x, int y) {
		if (!x or !y)
			return x + y;
		if (x >= y)
			return gcd(x % y, y);
		if (x <= y)
			return gcd(x, y % x);
	}

	void reduct(double eps = 0.00001) {
		if (!a and b) {
			b = 1;
			value = 0.0;
		}

		if (!b)
			return;

		bool aflag = a < 0; a = abs(a);
		bool bflag = b < 0; b = abs(b);

		while (!(abs(floor((a + 0.5)) - a) < eps and abs(floor((b + 0.5)) - b) < eps)) {
			a *= 10; b *= 10;
		}

		int c = gcd(int(float(a)), int(float(b)));
				a /= double(c);
				b /= double(c);

		if (!(aflag and bflag)) {
			a = aflag ? -a : a;
			a = bflag ? -a : a;
		}

	}

	Fract() { a = 0.0; b = 1.0; value = 0.0; }
	Fract(double n, double m) { a = n; b = m; if (b)value = a / b; reduct(); }
	Fract(int n, double m) { a = double(n); b = m; if (b)value = a / b; reduct(); }
	Fract(double n, int m) { a = n; b = double(m); if (b)value = a / b; reduct(); }
	Fract(int n, int m) { a = double(n); b = double(m); if (b)value = a / b; reduct(); }
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

	friend istream& operator >> (istream& in, Fract& other) {
		string val;
		cin >> val;
		string a_;
		int q = 0;
		while (val[q] != '/' and val[q]) {
			if (!((val[q] >= '0' and val[q] <= '9') or val[q] == '-' or val[q] == '.'))
				return in;
			a_ += val[q];
			q++;
		}
		if (a_ == val)
			other = Fract(stod(a_));
		else
		{
			int i = a_.size() + 1;
			string b_;
			for (int j = val.size(); i < j; i++)
				b_ += val[i];
			other = Fract(stod(a_), stod(b_));
		}
		return in;
	}

	string getVal() { return (b ? to_string(value) : "ERROR"); }

	Fract operator + (Fract& other) {
		Fract c = Fract(a * other.b + other.a * b, b * other.b);
		return c;
	}

	Fract operator - (Fract& other) {
		Fract c = Fract(a * other.b - other.a * b, b * other.b);
		return c;
	}

	Fract operator * (Fract& other) {
		Fract c = Fract(a * other.a, b * other.b);
		return c;
	}

	Fract operator / (Fract& other) {
		Fract c = Fract(a * other.b, b * other.a);
		return c;
	}
};

pair<int, int> func(int a, int b) {
	int q = 1;
	int x1 = 1;
	int x2 = 0;
	int y1 = 0;
	int y2 = 1;
	int i = 0;
	if (a > b) {
		int s = a;
		a = b;
		b = s;
	}
	int f;
	while (a and b) {
		if (!(i % 2)) {
			q = a / b;
			a = a % b;
			x1 -= q*x2;
			y1 -= q*y2;
			cout << q << " " << a << " " << x1 << " " << y1 << endl;
		}
		else {
			q = b / a;
			b = b % a;
			x2 -= q*x1;
			y2 -= q*y1;
			cout << q << " " << b << " " << x2 << " " << y2 << endl;
		}
		i++;
	}
	if (a)
		return pair<int,int>(y1,x1);
	return pair<int,int>(y2,x2);
}

int main() {
	
	return 0;
}
