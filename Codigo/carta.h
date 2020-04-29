#pragma once
#include <iostream>
#include <ostream>
#include <string>
class carta {
public:
	carta();
	carta(int x);
	friend std::ostream& operator <<(std::ostream& out, const carta& card);
	friend bool operator==(const carta& a, const carta& b);
	friend bool operator != (const carta & a, const carta & b);
	std::string getPalo();
	std::string getColor();
	int getNumero();
	bool isVisible();
	void setVisible(bool visible = false);
	std::string getOutxt();
private:
	std::string palo, color, outxt;
	int numero;
	bool visible;
};