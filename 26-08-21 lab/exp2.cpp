#include<iostream>
#include <cmath>
using namespace std;

// Class used to calculate the area of the Rectangle and Circle
class Area {
    private:
        float length, breadth;
        float radius;
    public:
        friend float rectangle(Area a, float l = 1, float b = 1);
        friend float circle(Area a, float r = 1);  
};

// Friend and Inline function for calculating the area of the rectangle
inline float rectangle(Area a, float l, float b){
    a.length = l;
    a.breadth = b;
    return(l * b);
}

// Friend and Inline function for calculating the area of the Circle
inline float circle(Area a, float r){
    a.radius = r;
    return (M_PI * r * r);
} 

// Class used to calculate the Volume of the Cuboid and the Sphere
class Volume {
    private:
        float length, breadth, height;
        float radius;
    public:
        friend float cuboid(Volume v, float l = 1, float b = 1, float h = 1);
        friend float sphere(Volume v, float r = 1); 
        // Function to compare the Volume of 2 cuboids using this pointer and area class    
        void compareCuboid(Volume v2){
            int choice;
            float volume1, volume2;
            cin >> choice;
            switch(choice){
                    case 1:
                        cout<<"Please enter the length, breadth and height for Cuboid1: ";
                        cin >> this->length >> this->breadth >> this->height;
                        volume1 = cuboid(*this,this->length,this->breadth,this->height);
                        cout<<"Please enter the length, breadth and height for Cuboid2: ";
                        cin >> v2.length >> v2.breadth >> v2.height;
                        volume2 = cuboid(v2, v2.length, v2.breadth, v2.height);
                        if(volume1 > volume2){
                            cout <<"Volume of Cuboid1: " << volume1 <<" is greater than volume of Cuboid2: " << volume2 <<endl;
                        }
                        else if(volume2 > volume1){
                            cout <<"Volume of Cuboid2: " << volume2 <<" is greater than volume of Cuboid1: " << volume1 <<endl;
                        }
                        else{
                            cout <<"Volume of Cuboid1: " << volume1 <<" is equal to volume of Cuboid2: " << volume2 <<endl;
                        }
                        break; 
                    case 2:
                        volume1 = cuboid(*this);
                        volume2 = cuboid(v2);
                        cout <<"As both are unit volume cuboids, Volume of Cuboid1: " << volume1 <<" is equal to volume of Cuboid2: " << volume2 <<endl;
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!\n";    
                }
        }
        // Function to compare the Volume of 2 spheres using this pointer and area class
        void compareSphere(Volume v2){
            int choice;
            float volume1, volume2;
            cin >> choice;
            switch(choice){
                    case 1:
                        cout<<"Please enter the radius for Sphere1: ";
                        cin >> this->radius;
                        volume1 = sphere(*this,this->radius);
                        cout<<"Please enter the radius for Sphere2: ";
                        cin >> v2.radius;
                        volume2 = sphere(v2, v2.radius);
                        if(volume1 > volume2){
                            cout <<"Volume of Sphere1: " << volume1 <<" is greater than volume of Sphere2: " << volume2 <<endl;
                        }
                        else if(volume2 > volume1){
                            cout <<"Volume of Sphere2: " << volume2 <<" is greater than volume of Sphere1: " << volume1 <<endl;
                        }
                        else{
                            cout <<"Volume of Sphere1: " << volume1 <<" is equal to volume of Sphere2: " << volume2 <<endl;
                        }
                        break;
                    case 2:
                        volume1 = sphere(*this);
                        volume2 = sphere(v2);
                        cout <<"As both are unit volume spheres, Volume of Sphere1: " << volume1 <<" is equal to volume of Sphere2: " << volume2 <<endl;
                        break;
                    default:
                        cout<<"Wrong choice, Please try again!\n";
                }
            
        }
};

// Friend and Inline function for calculating the volume of the Cuboid
inline float cuboid(Volume v, float l, float b, float h){
    v.length = l;
    v.breadth = b;
    v.height = h;
    Area temp;
    float area = rectangle(temp,l,b);
    return (area * h);
}

// Friend and Inline function for calculating the volume of the Sphere
inline float sphere(Volume v, float r){
    v.radius = r;
    Area temp;
    float area = circle(temp,r);
    return (area * (4.0/3) * r);
}

// Menu driven program in the main function
int main(){
    Area a;
    Volume v1, v2;
    int choice;
    float l,b,h,r;
    float l2,b2,h2,r2;
    float area, volume1, volume2;
    while(1){
        cout<<"Menu : \n 1)Calculate Area of Rectangle \n 2)Calculate Area of Circle \n 3)Unit Area of Rectangle \n 4)Unit Area of Circle \n 5)Unit Volume of Cuboid \n 6)Unit Volume of Sphere \n 7)Calculate Volume of Cuboid \n 8)Calculate Volume of Sphere \n 9)Compare Volume of 2 Cuboids \n 10)Compare Volume of 2 Spheres \n 11)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Please enter the length and breadth to calculate the area of the Rectangle: ";
                cin >> l >> b;
                area = rectangle(a,l,b);
                cout<<"Area of Rectangle is: "<< area << endl;
                break;
            case 2:
                cout<<"Please enter the radius to calculate the area of the Circle: ";
                cin >> r;
                area = circle(a,r);
                cout<<"Area of Circle is: "<< area << endl;
                break;
            case 3:
                area = rectangle(a);
                cout<<"Area of Rectangle is: "<< area << endl;
                break;
            case 4:
                area = circle(a);
                cout<<"Area of Circle is: "<< area << endl;
                break;
            case 5:
                volume1 = cuboid(v1);
                cout<<"Volume of Cuboid is: "<< volume1 << endl;
                break; 
            case 6:
                volume1 = sphere(v1);
                cout<<"Volume of Sphere is: "<< volume1 << endl;
                break;
            case 7:
                cout<<"Please enter the length, breadth and height to calculate the volume of the Cuboid: ";
                cin >> l >> b >> h;
                volume1 = cuboid(v1,l,b,h);
                cout<<"Volume of Cuboid is: "<< volume1 << endl;
                break;
            case 8:
                cout<<"Please enter the radius to calculate the volume of the Sphere: ";
                cin >> r;
                volume1 = sphere(v1,r);
                cout<<"Volume of Sphere is: "<< volume1 << endl;
                break; 
            case 9:
                cout<<"Please enter if you want to enter the parameters of the Cuboid(1) or not (2): ";
                v1.compareCuboid(v2);
                break;
            case 10:
                cout<<"Please enter if you want to enter the parameters of the Sphere(1) or not (2): ";
                v1.compareSphere(v2);
                break;
            case 11:
                exit(0);  
            default:
                cout<<"Wrong choice, Please try again!\n";                                       
        }
    }
    return 0;
}