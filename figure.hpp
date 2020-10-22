#ifndef FIGURE_LR
#define FIGURE_LR

#include "Vector2D.hpp"

class Figure{
    public:
        double Ax, Ay;
        double Bx, By;
        double Cx, Cy;
        double Dx, Dy;
        double cenX, cenY;
        double S;

        virtual void name(){
            cout << "Non";
        }

        void print_points(){
			cout << "Point A: (" << Ax << "," << Ay << ")" << endl;
			cout << "Point B: (" << Bx << "," << By << ")" << endl;
			cout << "Point C: (" << Cx << "," << Cy << ")" << endl;
			cout << "Point D: (" << Dx << "," << Dy << ")" << endl;
		}

        void print_S(){
            cout << "Area: " << S << endl;
        }

        void print_cen(){
            cout << "The center point: (" << cenX << "," << cenY << ")" << endl;
        }

        virtual void calS(){
            S = 0;
        }

        virtual void calC(){
            cenX = cenY = 0;
        }

};

class Rectangle: public Figure{
    public:
        Rectangle(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
            Ax = ax;
            Ay = ay;
            Bx = bx;
            By = by;
            Cx = cx;
            Cy = cy;
            Dx = dx;
            Dy = dy;
            calC();
            calS();
            cout << "Figure was created: ";
            cout << "RECTANGLE" << endl;
        }

        void name(){
            cout << "RECTANGLE" << endl;
        }

        void calS() override{
            Vector2D v1, v2;
			v1.Set(Ax, Ay, Bx, By);
			v2.Set(Bx, By, Cx, Cy);
			S = fabs(v1.l * v2.l);
        }

        void calC(){
            cenX = (Ax+Cx)/2;
            cenY = (Ay+Cy)/2;
        }
};

class Rhombus: public Figure{
    public:
        Rhombus(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
            Ax = ax;
            Ay = ay;
            Bx = bx;
            By = by;
            Cx = cx;
            Cy = cy;
            Dx = dx;
            Dy = dy;
            calC();
            calS();
            cout << "Figure was created: ";
            cout << "RHOMBUS" << endl;
        }

        void name(){
            cout << "RHOMBUS" << endl;
        }

        void calS() override{
            Vector2D v1, v2;
			v1.Set(Ax, Ay, Cx, Cy);
			v2.Set(Bx, By, Dx, Dy);
			S = fabs(v1.l * v2.l * 0.5);
        }

        void calC(){
            cenX = (Ax+Cx)/2;
            cenY = (Ay+Cy)/2;
        }
};

class Trapeze: public Figure{
    public:
        Trapeze(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
            Ax = ax;
            Ay = ay;
            Bx = bx;
            By = by;
            Cx = cx;
            Cy = cy;
            Dx = dx;
            Dy = dy;
            calC();
            calS();
            cout << "Figure was created: ";
            cout << "TRAPEZE" << endl;
        }

        void name(){
            cout << "TRAPEZE" << endl;
        }

        void calS() override{
            Vector2D v1, v2, v3, v4;
			v1.Set(Ax, Ay, Bx, By);
            v2.Set(Cx, Cy, Dx, Dy);
            v3.Set(Ax, Ay, Dx, Dy);
            v4.Set(Ax, Ay, Cx, Cy);
			if(!v1.in_parallel(v2)){
				v1.Set(Bx, By, Cx, Cy);
				v2.Set(Dx, Dy, Ax, Ay);
                v3.Set(Ax, Ay, Bx, By);
                v4.Set(Bx, By, Dx, Dy);
			}
            double polper = (v2.l + v3.l + v4.l)/2;
            double Str = sqrt(polper*(polper-v2.l)*(polper-v3.l)*(polper-v4.l));
			double h = 2*Str/v2.l;
			S = (0.5*(v1.l + v2.l)* h);
        }

        void calC(){
            double Jx, Jy, Gx, Gy;
            Vector2D v1, v2;
			v1.Set(Ax, Ay, Bx, By);
			v2.Set(Cx, Cy, Dx, Dy);
            if(!v1.in_parallel(v2)){
                Jx = (Ax+Dx)/2;
                Jy = (Ay+Dy)/2;
                Gx = (Bx+Cx)/2;
                Gy = (By+Cy)/2;
                cenX = (Jx+Gx)/2;
                cenY = (Jy+Gy)/2;
            } else{
                Jx = (Ax+Bx)/2;
                Jy = (Ay+By)/2;
                Gx = (Dx+Cx)/2;
                Gy = (Dy+Cy)/2;
                cenX = (Jx+Gx)/2;
                cenY = (Jy+Gy)/2;
            }
        }
};

int sort(double a, double b, double c, double d, double e, double f, double g, double h){
    Vector2D v1, v2, v3, v4, v5, v6;
    v1.Set(a, b, c, d);
    v2.Set(c, d, e, f);
    v3.Set(e, f, g, h);
    v4.Set(g, h, a, b);
    v5.Set(a, b, e, f);
    v6.Set(c, d, g, h);
    if(v1.perpendicularity(v2) && v1.perpendicularity(v4) && v3.perpendicularity(v2) && v3.perpendicularity(v4)){
        return 1;
    } else if(v1.in_parallel(v3) && v2.in_parallel(v4) && v5.perpendicularity(v6)){
        return 2;
    } else if((v1.in_parallel(v3) && !v2.in_parallel(v4)) || (!v1.in_parallel(v3) && v2.in_parallel(v4))){
        return 3;
    } else{
        return 0;
    }
}

#endif //FIGURE_LR