#include<iostream>
#include<string>


bool checkRecord(std::string& record){
    int pointL{0},pointA{0};
    for(int i{0}; i<record.size(); i++){
        if(record[i] == 'A'){
            pointA++;
            pointL=0;
            if(pointA > 1){
                return false;
            }
        }
        else if(record[i] == 'L'){
            pointL++;
            if(pointL > 2){
                return false;
            }
        }
        else{
            pointL=0;
        }
    }
    return true;
}



int main(){
    std::string record_a{"PPALLP"};
    std::string record_b{"PPALLL"};

    std::cout<<checkRecord(record_a)<<std::endl;
    std::cout<<checkRecord(record_b)<<std::endl;

}
