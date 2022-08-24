#include <iostream>
#include "vector"

bool inRange(int a,int size){
    if(a>=0&&a<=size-1) return true;
    std::cout << "coordinate must be in range [0.."<<size-1<<"]" << std::endl;
    return false;
}

bool input(int coord[],int size){
    int a;
    std::string str[4]={"X1","Y1","X2","Y2"};
    for(int i=0;i<4;++i){
        do {
            std::cout << "Input coords " << str[i]<<"[0..11]:";
            std::cin >> coord[i];
        }while(!inRange(coord[i],size));
    }
    std::cout << std::endl;
    return true;
}

void init(bool a[][12],int size){
    //std::vector<std::vector<bool>> a;
    //a.resize(size);
    for(int i=0;i</*a.*/size/*()*/;++i){
        //a[i].resize(size);
        for(int k=0;k</*a[i].*/size/*()*/;++k){
            a[i][k]=true;
        }
    }
//    return a;
}

int print(bool a[][12]){
    int counter=0;
    for (int i=0;i<12;++i){
        for (int k=0;k<12;++k){
           if (a[i][k]) {
               std::cout<<"o";
               ++counter;
           }
           else std::cout<<"x";
        }
        std::cout << std::endl;
    }
    return counter;
}

int pop(bool a[][12], int coord[]){
    if (coord[0] > coord[2])std::swap(coord[0],coord[2]);
    if (coord[1] > coord[3])std::swap(coord[1],coord[3]);
    for (int i=coord[0];i<12&&i<=coord[2];++i){
        for(int k=coord[1];k<12&&k<=coord[3];++k){
            if(a[i][k]) {
                std::cout << "Pop"<<std::endl;
                a[i][k]=false;
            }
        }
    }
    return print(a);
}

int main() {
    const int size =12;
    int coord[4]={0,0,0,0};
    std::cout << "Pops are ready:" << std::endl;
    bool pops[size][size];
    init(pops,size);
    print(pops);
    input(coord,size);
    while(0!=pop(pops,coord)){
        input(coord,size);
        print(pops);
    };

    return 0;
}
