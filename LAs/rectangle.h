//
// Created by 35814 on 3/7/2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;


class rectangle {
	private:
		double m_length;
	    double m_width;

 	public:
    	rectangle(double length, double width): m_length(length), m_width(width) {}

        double area() {
        	return m_length * m_width;
        }

        friend void printRectangleInfo(rectangle &r);
};

void printRectangleInfo(rectangle &r) {
	cout << "length: " << r.m_length << endl;
    cout << "width: " << r.m_width << endl;
    cout << "area: " << r.area() << endl;
}


#endif //RECTANGLE_H
