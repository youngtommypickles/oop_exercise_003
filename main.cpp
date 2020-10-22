#include "figure.hpp"
#include <vector>

void menu(){//меню для работы
    cout << "______________________________" << endl;
    cout << "|                            |" << endl;
    cout << "|            Menu            |" << endl;
    cout << "|____________________________|" << endl;
    cout << "|                            |" << endl;
    cout << "|1  - Add Figure             |" << endl;
    cout << "|2  - Delete Figure          |" << endl;
    cout << "|3  - Sum of areas           |" << endl;
    cout << "|4  - Working with a figure  |" << endl;
    cout << "|5  - All figures            |" << endl;
    cout << "|0  - Stop                   |" << endl;
    cout << "|____________________________|" << endl;
}

int main(){
    int option1, option2, i;
    vector <Figure*> vec;
    double a, b, c, d, e, f, g, h;
    menu();
    for(;;){
        cin >> option1;
        switch(option1){
            case 1:{
                cout << "Enter the values of the x and y coordinate points" << endl;
                cout << "A: ";
                cin >> a >> b;
                cout << "B: ";
                cin >> c >> d;
                cout << "C: ";
                cin >> e >> f;
                cout << "D: ";
                cin >> g >> h;
                if(sort(a, b, c, d, e, f, g, h) == 1){
                    vec.push_back(new Rectangle(a, b, c, d, e, f, g, h));
                }else if(sort(a, b, c, d, e, f, g, h) == 2){
                    vec.push_back(new Rhombus(a, b, c, d, e, f, g, h));
                }else if(sort(a, b, c, d, e, f, g, h) == 3){
                    vec.push_back(new Trapeze(a, b, c, d, e, f, g, h));
                } else{
                    cout << "Error" << endl;
                    break;
                }
                break;
            }
            case 2:{
                cout << "Enter figure number: ";
                cin >> i;
                auto iter = vec.cbegin();
                if(i > vec.size() && i>=0){
                    cout << "There are " << vec.size() << " figures" << endl;
                    cout << "Try again!" << endl;
                    break;
                }
                vec.erase(iter + i - 1);
                cout << "Figure was deleted!" << endl;
                break;
            }
            case 3:{
                if(vec.size() == 0){
                    cout << "S = 0" << endl;
                    break;
                } else{
                    double S = 0;
                    for(int i=0; i < vec.size(); ++i){
                        S+=vec[i]->S;
                    }
                    cout << "S = " << S << endl;
                }
                break;
            }
            case 4:{
                cout << "Enter figure number: ";
                cin >> i;
                if(i > vec.size() && i >= 0){
                    cout << "There are " << vec.size() << " figures" << endl;
                    cout << "Try again!" << endl;
                    break;
                }
                vec[i-1]->name();
                vec[i-1]->print_points();
                vec[i-1]->print_cen();
                vec[i-1]->print_S();
                break;
            }
            case 5:{
                if(!vec.size()){
                    cout << "There are " << vec.size() << " figures" << endl;
                    break;
                }
                cout << "There are " << vec.size() << " figures" << endl;
                for(int n = 0; n < vec.size(); ++n){
                    cout << n+1 << ".";
                    vec[n]->name();
                    cout << endl;
                }
                break;
            }
            default:
                cout << "Try again!" << endl;
                break;
            case 0:
                vec.clear();
                return 0;       
        }
    }
    return 0;
}