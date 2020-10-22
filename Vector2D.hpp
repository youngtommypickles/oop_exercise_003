#ifndef VECTOR2D
#define VECTOR2D

#include <iostream>
#include <cmath>
using namespace std;

class Vector2D{
	public:
		double x, y;
		double l;

		void Set(double x1, double y1, double x2, double y2){
			x = x2 - x1;
			y = y2 - y1;
			l = sqrt(x*x + y*y);
		}

		bool in_parallel(Vector2D v){
			if(x * v.y == y * v.x){
				return true;
			} else{
				return false;
			}
		}

		bool perpendicularity(Vector2D v){
			if(x * v.x + y * v.y){
				return false;
			} else{
				return true;
			}
		}
};

#endif //VECTOR2D