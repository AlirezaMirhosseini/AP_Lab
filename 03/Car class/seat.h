#pragma once

#include "date.h"

class seat{
private:
	//const date prdct_date;
	string s_color;
	string material;
	date prdct_date;
public:
	void DATE();
	void set_DATE(int _year, int _month, int _day);
	void set_s_color(string _s_color);
	void set_material(string _material);
	string get_s_color();
	string get_material();
	//const date get_prdctdate()const;
};