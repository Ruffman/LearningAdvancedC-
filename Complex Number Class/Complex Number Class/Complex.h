#pragma once

#include <iostream>

namespace Ruff {

	class Complex
	{
	private:
		double _real = 0.0;
		double _imaginary = 0.0;

	public:
		Complex();
		Complex(const Complex& other);
		Complex(double real, double imaginary);
		~Complex();

		const Complex& operator=(const Complex& other);
		Complex operator*() const;

		double getReal() const { return _real; }; //need const so overloaded << works with const object!
		double getImaginary() const { return _imaginary; };
	};

	std::ostream& operator<<(std::ostream& out, const Complex& complex);
	Complex operator+(const Complex& lhs, const Complex& rhs);
	Complex operator+(const Complex& lhs, double rhs);
	Complex operator+(double lhs, const Complex& rhs);
	bool operator==(const Complex& lhs, const Complex& rhs);
	bool operator!=(const Complex& lhs, const Complex& rhs);


} //END namespace Ruff