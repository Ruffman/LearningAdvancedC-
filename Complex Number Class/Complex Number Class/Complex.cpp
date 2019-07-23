#include "pch.h"
#include "Complex.h"


using namespace Ruff;


Complex::Complex()
{
}

Complex::Complex(const Complex& other) : _real(other._real), _imaginary(other._imaginary)
{
}

Complex::Complex(double real, double imaginary) : _real(real), _imaginary(imaginary)
{
}

Complex::~Complex()
{
}

const Complex& Complex::operator=(const Complex& other)
{
	_real = other._real;
	_imaginary = other._imaginary;
	return *this;
}

Complex Ruff::Complex::operator*() const
{
	return Complex(_real, -_imaginary);
}

std::ostream& Ruff::operator<<(std::ostream& out, const Complex& complex)
{
	out << complex.getReal() << "/" << complex.getImaginary() << std::endl;
	return out;
}

Complex Ruff::operator+(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.getReal() + rhs.getReal(), lhs.getImaginary() + rhs.getImaginary());
}

Complex Ruff::operator+(const Complex & lhs, double rhs)
{
	return Complex(lhs.getReal() + rhs, lhs.getImaginary());
}

Complex Ruff::operator+(double lhs, const Complex & rhs)
{
	return Complex(lhs + rhs.getReal(), rhs.getImaginary());
}

bool Ruff::operator==(const Complex & lhs, const Complex & rhs)
{
	if (lhs.getReal() != rhs.getReal())
	{
		return false;
	}
	else if (lhs.getImaginary() != rhs.getImaginary())
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Ruff::operator!=(const Complex & lhs, const Complex & rhs)
{
	if (lhs == rhs)
	{
		return false;
	}
	else
	{
		return true;
	}
}
