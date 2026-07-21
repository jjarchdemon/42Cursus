#include <iostream>

class Fixed
{
private:
	int m_value;
	static const int FRACTIONAL_BITS = 8;

public:
	Fixed() : m_value(0)
	{
		std::cout << "Default constructor called" << std::endl;
	}

	// copy constructor
	Fixed(Fixed const &other)
	{
		std::cout << "Copy constructor called" << std::endl;
		*this = other; // delegate to overloaded assignment operator
	}

	// copy assignment operator overload
	Fixed &operator=(Fixed const &other)
	{
		std::cout << "Copy assignment operator called" << std::endl;
		if (this != &other)
			m_value = other.getRawBits();
		return *this;
	}

	// destructor
	~Fixed()
	{
		std::cout << "Destructor called" << std::endl;
	}

	int getRawBits(void) const
	{
		return m_value;
	}

	void setRawBits(int const raw)
	{
		std::cout << "setRawBits member function called" << std::endl;
		m_value = raw;
	}
};

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}

// TODO: refactor