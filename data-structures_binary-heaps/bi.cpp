#include<iostream>
#include<vector>

using namespace std;

template<typename Object>
class BinaryHeap{
   public:
      explicit BinaryHeap(int initCapacity=10){
         heapArray.resize(initCapacity);
      };
      
      explicit BinaryHeap(const vector<Object>& items){
         heapArray.resize(items.size() + 10);
         for(int i{0}; i<items.size(); i++){
            insert(items[i]);
         }
      }
      bool isEmpty() const;
      const Object& findMin() const;

      void insert(Object x){
         percolateUp(x);
      }
      void deleteMin(){
         heapArray[1] = std::move(heapArray[currentSize--]);
         percolateDown(1);
      }
      void sort(){
         sortByDescendingOrder();
      }
      void print(){
         for(int i{1}; i<=currentSize; i++){
            std::cout<<heapArray[i]<<" ";
         }
         std::cout<<std::endl;
      }
   
   private:
      int currentSize{0};
      vector<Object> heapArray;

      void buildHeap(){
        for(int i{1}; heapArray.size(); i++){
           percolateDown(i);
        }     
      }
      void percolateUp(Object x){
         if(currentSize == heapArray.size())
            heapArray.resize(heapArray.size() * 2);

         int hole = ++currentSize;

         heapArray[0] = std::move(x);

         for(; x<heapArray[hole/2]; hole /= 2){
            heapArray[hole] = heapArray[hole / 2];
         }
         heapArray[hole] = std::move(heapArray[0]);
      }
      void percolateDown(int hole){
         heapArray[0] = heapArray[1];

         for(int child{0}; child<currentSize; hole=child){
            child = hole * 2;
            
            if(child+1 <= currentSize && 
               heapArray[child+1] < heapArray[child]){
               
               ++child;
            }
            if(child<=currentSize &&
               heapArray[child] < heapArray[0]){
               
               heapArray[hole] = heapArray[child];
            }
            else break;
         }
         heapArray[hole] = heapArray[0];
      }
      void sortByDescendingOrder(){
         int originalSize{currentSize};
         while(currentSize > 0){
            heapArray[0] = heapArray[1];
            heapArray[1] = heapArray[currentSize];
            heapArray[currentSize] = heapArray[0];
            --currentSize;
            percolateDown(1);
         }

         currentSize = originalSize;
      }
};


int main(){
   BinaryHeap<int> b;

   b.insert(50);
   b.insert(200);
   b.insert(10);
   b.print();
   b.insert(30);
   b.insert(20);
   b.insert(1);
   b.insert(15);
   b.print();
   b.insert(300);
   b.print();
   std::cout<<std::endl;
   b.deleteMin();
   b.print();
   std::cout<<std::endl;
   b.sort();
   b.print();
   std::cout<<std::endl;

   
   std::vector<int> nums{4,3,2,6,7,5,20,30,33,1};
   BinaryHeap<int> b_list{nums};
   
   b_list.print();
   b_list.sort();
   b_list.print();
   
}
