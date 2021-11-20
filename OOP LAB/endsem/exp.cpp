#include <iostream>
#include <cstdlib>
using namespace std;

// A class Shape which contains area data member
class Shape {
    protected:
        float area;
    public:
        void Display(){
            cout<<"Area of the given shape is "<<area<<"\n";
        }        
};

// A class Quadrilateral inherited from Shape
class Quadrilateral: public Shape {
    protected:
        float side1, side2, side3, side4;
    public:
        void setData(float a, float b, float c, float d){
            side1 = a;
            side2 = b;
            side3 = c;
            side4 = d;
        }
        void calculateArea(){
            area = side1*side2*side3*side4;
        }
        void getData(){
            cout<<"Side1: "<<side1<<" Side2: "<<side2<<" Side3: "<<side3<<" Side4: "<<side4<<"\n";
            Shape::Display();
        }

};

// A class Rectangle inherited from Quadrilateral
class Rectangle: public Quadrilateral {
    public:
        void setData(float length, float breadth){
            side1 = length;
            side2 = breadth;
            side3 = 1;
            side4 = 1;
        }
        void calculateArea(){
            area = side1*side2;
        }
        void getData(){
            cout << "\x1B[31m----------Rectangle Details------------\033[0m\n";
            cout<<"Length: "<<side1<<" Breadth: "<<side2<<"\n";
            cout<<"The Area of the Rectangle is: "<<area<<"\n";
        }
};

// A class Square inherited from Quadrilateral
class Square: public Quadrilateral {
    public:
        void setData(float length){
            side1 = length;
            side2 = 1;
            side3 = 1;
            side4 = 1;
        }
        void calculateArea(){
            area = side1*side1;
        }
        void getData(){
            cout << "\x1B[32m----------Square Details------------\033[0m\n";
            cout<<"Length: "<<side1<<"\n";
            cout<<"The Area of the Square is: "<<area<<"\n";
        }
};

// A class Triangle inherited from Shape
class Triangle: public Shape {
    private:
        float base, height;
    public:
        void setData(float b, float h){
            base = b;
            height = h;
        }
        void calculateArea(){
            area = (base*height)/2;
        }
        void getData(){
            cout << "\x1B[37m----------Triangle Details------------\033[0m\n";
            cout<<"Base: "<<base<<" Height: "<<height<<"\n";
            cout<<"The Area of the Triangle is: "<<area<<"\n";
        }

};

// Main driver Program(menu)
int main(){
    Shape *shape_head = NULL;
    int choice;
    int size1 = -1, size2 = -1, size3 = -1;
    int count1 = 0, count2 = 0, count3 = 0;
    float a, b;
    while(size1 <= 0){
        cout<<"Please enter the maximum size of list of Squares: ";
        cin >> size1;
        if(size1 <=  0){
            cout <<"Invalid size, Please try again!\n";
        }
    }
    while(size2 <= 0){
        cout<<"Please enter the maximum size of list of Rectangles: ";
        cin >> size2;
        if(size2 <=  0){
            cout <<"Invalid size, Please try again!\n";
        }
    }
    while(size3 <= 0){
        cout<<"Please enter the maximum size of list of Triangles: ";
        cin >> size3;
        if(size3 <=  0){
            cout <<"Invalid size, Please try again!\n";
        }
    }
    Square arr1[size1];
    Rectangle arr2[size2];
    Triangle arr3[size3];
    while(1){
        cout<<"Menu : \n 1)Create a Shape \n 2)Calculate Area \n 3)Display Details \n 4)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        if(choice == 1){
            int option;
            cout<<"Please enter 1 for Square, 2 for Rectangle, 3 for Triangle: ";
            cin >> option;
            if(option == 1){
                if(count1 < size1){
                    Square obj;
                    cout<<"Please enter the length of the Square: ";
                    cin >>a;
                    try{
                        if(a < 0){
                            throw a;
                        }
                    }
                    catch(float a){
                        cerr<<"Invalid Square length\n";
                    }
                    obj.setData(a);
                    arr1[count1] = obj;
                    count1++;
                }
                else {
                    cout<<"The list of Squares has reached it's Maximum size!!\n";
                }
            }
            else if(option == 2){
                if(count2 < size2){
                    Rectangle obj;
                    cout<<"Please enter the length and Breadth of the Rectangle: ";
                    cin >>a >> b;
                    try{
                        if(a < 0){
                            throw a;
                        }
                        else if(b < 0){
                            throw b;
                        }
                    }
                    catch(float a){
                        cerr<<"Invalid Rectangle length or Breadth\n";
                    }
                    obj.setData(a, b);
                    arr2[count2] = obj;
                    count2++;
                }
                else{
                    cout<<"The list of Rectangles has reached it's Maximum size!!\n";
                }    
            }
            else if(option == 3){
                if(count3 < size3){
                    Triangle obj;
                    cout<<"Please enter the Base and Height of the Triangle: ";
                    cin >>a >> b;
                    try{
                        if(a < 0){
                            throw a;
                        }
                        else if(b < 0){
                            throw b;
                        }
                    }
                    catch(float a){
                        cerr<<"Invalid Triangle Base or Height\n";
                    }
                    obj.setData(a, b);
                    arr3[count3] = obj;
                    count3++;
                }
                else {
                    cout<<"The list of Triangles has reached it's Maximum size!!\n";
                }    
            }
            else {
                cout<<"Wrong choice, Please try again!\n";
            }            
        }
        else if(choice == 2){
            for(int i = 0; i < count1; i++){
                arr1[i].calculateArea();
            }
            for(int i = 0; i < count2; i++){
                arr2[i].calculateArea();
            }
            for(int i = 0; i < count3; i++){
                arr3[i].calculateArea();
            }
        }
        else if(choice == 3){
            if(count1 == 0 && count2 == 0 && count3 == 0){
                cout<<"The List is empty!!\n";
            }
            else {
                for(int i = 0; i < count1; i++){
                    arr1[i].getData();
                }
                for(int i = 0; i < count2; i++){
                    arr2[i].getData();
                }
                for(int i = 0; i < count3; i++){
                    arr3[i].getData();
                }
            }
        }
        else if(choice == 4){
            exit(0);
        }
        else {
            cout<<"Wrong choice, Please try again!\n";
        }
    }
    return 0;
}