// This program is done by CS20B1044 Avinash R Changrani
/*  Question : Create a class called Product. The product has productName, uniqueNo, price, gst,stock members; stock denotes the number
of those products available in the shop. Create a singly linked list of Product objects. Create an friend function which 
returns the number of stocks available for a given product. Also, write a function that adds a new product at the end of 
the list. A display function traverses the SLL of products and print their product names and price.
Follow the coding best practices and maintain proper boundary conditions.
The program should be menu driven and the menu is as follows:
1. Set Product Details.
2. Number of Stock Available.
3. Append a new product
4. Display.
5. Exit.
*/
#include <iostream>
using namespace std;

class Product {
    private :
        string productName;
        int uniqueNo, stock;
        double price, gst;
    public :
        Product *next;   
        friend int availableStock(Product *); 
        // A function to get Product details, using which we add it to the Product Linkedlist
        Product* addProduct(){
            int unique_no;
            double Price;
            cout<<"Please enter the Unique Number of the Product: ";
            cin >> unique_no;
            cout<<"Please enter the Price of the Product: ";
            cin >> Price;
            if(Price >= 0){
                this->price = Price;
            }    
            else {
                this->price = 0.0;
                cout<<"Please enter a non-negative price and try again.(Price has been set to 0)"<<endl;
            }   
            this->uniqueNo = unique_no; 
            this->productName = "Product";
            this->stock = 0;
            this->gst = 0;
            return this;
        }
        // A function to get Product object based on Unique Number
        Product* getProduct(Product *head, int unique_no){
            Product* ptr = new Product();
            if(head == NULL){
                cout << "List of Products is Empty! Please try again" << endl;
                return NULL;
            }
            else {
                ptr = head;
                while(ptr != NULL){
                    if(ptr->uniqueNo == unique_no){
                        return ptr;
                    }
                    else if(ptr->uniqueNo != unique_no && ptr->next == NULL){
                        cout<<"No such Unique Number of a Product exists! Please try again"<< endl;
                        return NULL;
                    }
                    ptr = ptr->next;
                }
            }

        }
        // A function for setting details of a Product
        void setDetails(Product *p, int option){
            if(option == 1){
                string name;
                cout<<"Please enter the Product Name of the Product: ";
                getline(cin >> ws, name);
                p->productName = name;
            }
            else if(option == 2){
                int Stock;
                cout<<"Please enter the Stock Available for the Product: ";
                cin >> Stock;
                if(stock >= 0){
                    p->stock = Stock;
                }
                else{
                    cout<<"Please enter a valid Stock Number!!\n";
                }
            }
            else if(option == 3){
                double GST;
                cout<<"Please enter the GST of the Product: ";
                cin >> GST;
                p->gst = GST;
            }
            else{
                cout<<"Wrong choice, Please try again!\n";  
            }
        }
        // A function for displaying all the products in the linked List
        void Display(Product *head){
            Product* ptr = new Product();
            if(head == NULL){
                cout << "List of Products is Empty! Please try again" << endl;
                return;
            }
            else {
                ptr = head;
                while(ptr != NULL){
                    cout<<"Product Name: "<<ptr->productName<<" Unique Number: "<<ptr->uniqueNo<<" Price: "<<ptr->price<<" Stock: "<< ptr->stock<<" GST: "<< ptr->gst<<"\n";
                    ptr = ptr->next;
                }
            }

        }
};

// A friend function to get the stock of a product
int availableStock(Product *p){
    return(p->stock);
}

int main() {
    int choice, unique_no, stock, option;
    Product *product_head = NULL;
    Product temp1;
    while(1){
        cout<<"Menu : \n 1)Set Product Details \n 2)Number of Stock Available \n 3)Append a new product \n 4)Display \n 5)Exit";
        cout<<"\nPlease Enter your choice: ";
        cin>>choice;
        if(choice == 1){
            cout<<"Please enter the Unique Number of the Product you wish to set details of: ";
            cin >> unique_no;
            if(temp1.getProduct(product_head, unique_no) != NULL){
                Product *ptr = temp1.getProduct(product_head, unique_no);
                cout<<"Please enter 1 for setting Product Name, 2 for Stock and 3 for GST: ";
                cin >>option;
                temp1.setDetails(ptr, option);
            }
            else{
                cout<<"Please enter a valid Unqiue Number (of the Product)!!\n";
            }
        }
        else if(choice == 2){
            cout<<"Please enter the Unique Number of the Product you wish to know the available stock of: ";
            cin >> unique_no;
            if(temp1.getProduct(product_head, unique_no) != NULL){
                Product *ptr = temp1.getProduct(product_head, unique_no);
                stock = availableStock(ptr);
                cout<<"The stock for the Product with Unique Number: "<<unique_no<<" is "<<stock<<"\n";
            }
            else{
                cout<<"Please enter a valid Unqiue Number (of the Product)!!\n";
            }
        }    
        else if(choice == 3){
            Product *temp = new Product;
            if(product_head == NULL){
                temp->addProduct();
                temp->next = NULL;
                product_head = temp;
                product_head->next = NULL;
            }
            else {
                Product* ptr = product_head;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                temp->addProduct();
                temp->next = NULL;
                ptr->next = temp;
            }
        }
        else if(choice == 4){
            temp1.Display(product_head);
        }    
        else if(choice == 5){
            exit(0);
        }    
        else {
            cout<<"Wrong choice, Please try again!\n";  
        }              
    }
    return 0;
}
// CS20B1044 Avinash R Changrani