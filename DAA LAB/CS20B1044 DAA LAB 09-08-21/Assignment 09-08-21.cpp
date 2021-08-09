#include<iostream>
#include <vector>

class minMaxProgram{
private:
    std::vector<int> minMaxArray;
public:

    void arrayAdder(int element){
        minMaxArray.push_back(element);
    }

    void linearFinder(void){
        int min,max,sMin,sMax;
        min=minMaxArray[0];
        max=minMaxArray[0];
        for (int i = 0; i < minMaxArray.size(); ++i) {
            if(minMaxArray[i]>max) {
                max = minMaxArray[i];
            }
            if(minMaxArray[i]<min) {
                min = minMaxArray[i];
            }
        }

        std::vector<int> secondMinMaxArray;
        for (int i = 0; i <minMaxArray.size(); ++i) {
            if(!(minMaxArray[i]==max || minMaxArray[i]==min))
                secondMinMaxArray.push_back(minMaxArray[i]);
        }

        if(secondMinMaxArray.size()!=0) {
            sMin = secondMinMaxArray[0];
            sMax = secondMinMaxArray[0];

            for (int i = 0; i < secondMinMaxArray.size(); ++i) {
                if (secondMinMaxArray[i] > sMax) {
                    sMax = secondMinMaxArray[i];
                }
                if (secondMinMaxArray[i] < sMin) {
                    sMin = secondMinMaxArray[i];
                }
            }
        }

        if(secondMinMaxArray.size()!=0)
            std::cout << "THE MIN MAX SMIN SMAX ARE " << min <<" " << max << " "<< sMin << " " << sMax << "\n";
        else
            std::cout << "THE MIN MAX ARE " << min <<" " << max << "\n";

    }

    void binaryMaxMin(int &max,int &min,std::vector<int> array,int l,int r){
        if(l-r==0){
            max=min=array[l];
        }
        else if(((l-r)==1||(l-r)==-1)){
            if(array[l]>=array[r]){
                max=array[l];
                min=array[r];
            }
            else{
                min=array[l];
                max=array[r];
            }
        }
        else{
            int maxL,maxR,minL,minR;
            binaryMaxMin(maxL,minL,array,l,((l+(r-1))/2));
            binaryMaxMin(maxR,minR,array,(((l+(r-1))/2)+1),r);
            if(maxL>=maxR)
                max=maxL;
            else
                max=maxR;

            if(minL<=minR)
                min=minL;
            else
                min=minR;
        }
    }

    void binary_finder(){
        int max,min,sMin,sMax;
        minMaxProgram::binaryMaxMin(max,min,minMaxArray,0,minMaxArray.size()-1);
        std::vector<int> secondMinMaxArray;
        for (int i = 0; i < minMaxArray.size(); ++i) {
            if(!(minMaxArray[i]==max || minMaxArray[i]==min))
                secondMinMaxArray.push_back(minMaxArray[i]);
        }
        if(minMaxArray.size()>2){

            minMaxProgram::binaryMaxMin(sMax,sMin,secondMinMaxArray,0,secondMinMaxArray.size()-1);
            std::cout << "THE MIN MAX SMIN SMAX ARE " << min <<" " << max << " "<< sMin << " " << sMax << "\n";
        }
        else
            std::cout << "THE MIN MAX ARE " << min <<" " << max << "\n";
    }

    void array_printer(){
        std::cout<<"THE ARRAY IS\n";
        for (int i = 0; i < minMaxArray.size(); ++i) {
            std::cout<<minMaxArray[i]<<" ";
        }
        std::cout<<"\n";
    }

    void pairCompare(int &min,int &max, std::vector<int> minMaxArray, int size){
        int i;
        if(size%2 == 0){
            if(minMaxArray[0]>minMaxArray[1]){
                max = minMaxArray[0];
                min = minMaxArray[1];
            }
            else{
                max = minMaxArray[1];
                min = minMaxArray[0];
            }
            i = 2;
        }
        else{
            min = minMaxArray[0];
            max = minMaxArray[0];
            i = 1;
        }
        while(i<size){
            if(minMaxArray[i]>minMaxArray[i+1]){
                if (minMaxArray[i]>max) {
                    max=minMaxArray[i];
                }
                if(minMaxArray[i+1]<min){
                    min = minMaxArray[i+1];
                }
            }
            else{
                if (minMaxArray[i+1]>max) {
                    max=minMaxArray[i+1];
                }
                if(minMaxArray[i]<min){
                    min = minMaxArray[i];
                }
            }

            i=i+2;
        }
    }

    void minMaxComp(){
        int max, min, sMax, sMin;
        std::vector<int> secondMinMaxArray;
        pairCompare(min,max,minMaxArray,minMaxArray.size());
        for (int i = 0; i < minMaxArray.size(); ++i) {
            if(!(minMaxArray[i]==max || minMaxArray[i]==min))
                secondMinMaxArray.push_back(minMaxArray[i]);
        }
        if(secondMinMaxArray.size()!=0){
            pairCompare(sMin,sMax,secondMinMaxArray,secondMinMaxArray.size());
            std::cout << "THE MIN MAX SMIN SMAX ARE " << min <<" " << max << " "<< sMin << " " << sMax << "\n";
        }
        else
            std::cout << "THE MIN MAX ARE " << min <<" " << max << "\n";
    }

};

int main(void){
    std::cout  << "PLEASE ENTER THE ELEMENTS IN THE ARRAY\n";
    minMaxProgram requiredArray;
    int elements_entry = 1;
    while(elements_entry){
        if(elements_entry ==1){
            std::cout<<"PLEASE ENTER THE ELEMENT FOR THE ARRAY\n";
            int arrayElement;
            std::cin>>arrayElement;
            requiredArray.arrayAdder(arrayElement);
        }
        else{
            std::cout<<"Please choose an valid operation.\n";
        }
        std::cout<<"ENTER 1 IF YOU WANT ADD MORE ELSE 0\n";
        std::cin>>elements_entry;
    }
    requiredArray.array_printer();
    std::cout<<"THE EXTREMES FROM LINEAR FINDER ALGORITHM ARE\n";
    requiredArray.linearFinder();
    std::cout<<"THE EXTREMES FROM BINARY FINDER ALGORITHM ARE\n";
    requiredArray.binary_finder();
    std::cout<<"THE EXTREMES FROM PAIR COMP ALGORITHM ARE\n";
    requiredArray.minMaxComp();
    return 0;
}