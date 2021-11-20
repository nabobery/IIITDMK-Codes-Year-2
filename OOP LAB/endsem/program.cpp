// This program is done by CS20B1044 Avinash R Changrani
/* Question : Write a C++ program to implement the following.
Class Shape having data member area. A member function display to display the area of the shape.
Class Quadrilateral inherits Shape. It has 4 data members for 4 sides. It has three member functions,
setData, getData, calculateArea. Set data sets the value for the 4 sides. Get data displays the sides
and area. Calculate area calculates the area of the Quadrilateral.
Class Rectange inherits Quadrilateral. Write functions to override all the functions of its super class.
Set sides 1 and 2 as length and breadth and sides 3 and 4 as 1.
Class Square inherits Quadrilateral. Write functions to override all the functions of its super class.
Set side 1 as length and sides 2, 3 and 4 as 1.
Class Triangle inherits Shape. It has two data members base and height. It has three member
functions, setData, getData, calculateArea. Set data sets the value for the 3 sides. Get data displays
the sides and area. Calculate area calculates the area of the triangle.
The menu is as follows:
1) Create a shape
2) Calculate area
3) Display details
4) Exit
Maintain a list of all shapes.
In create shape option, get input for shape(square, rectangle or triangle) from the user and get
details for that shape.
In calculate area, calculate area for all shapes in the lists and store it.
In display, display the details of all shapes.
Details to be displayed: Shape, Sides, Area
Use any access specifier which you prefer is suitable.
All necessary boundary conditions need to checked using try and catch blocks.
Follow good coding practices. Do not use STL
*/

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
                    if(a < 0){
                        cout<<"Invalid Square length\n";
                    }
                    else {
                        obj.setData(a);
                        arr1[count1] = obj;
                        count1++;
                    }  
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
                    if(a < 0 || b < 0){
                        cout<<"Invalid Rectangle length or Breadth\n";
                    }
                    else{
                        obj.setData(a, b);
                        arr2[count2] = obj;
                        count2++;
                    }
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
                    if(a < 0 || b < 0){
                        cout<<"Invalid Triangle Base or Height\n";
                    }
                    else{
                        obj.setData(a, b);
                        arr3[count3] = obj;
                        count3++;
                    }
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
            if(count1 == 0 && count2 == 0 && count3 == 0){
                cout<<"The List is empty!!\n";
            }
            else {
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