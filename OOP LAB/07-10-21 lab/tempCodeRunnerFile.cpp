template <class T> class person {
    protected:
        string name;
        //template <typename T> 
        T roll_no;
    public:
        // person(){}
        person(string Name, T rollNumber){
            name = Name;
            roll_no = rollNumber;
        }
        void Display(){
            //cout << "\x1B[37m----------Person Details------------\033[0m\n";
            cout<<"Name: "<< name << " Roll Number: "<< roll_no << "\n";
        }

};