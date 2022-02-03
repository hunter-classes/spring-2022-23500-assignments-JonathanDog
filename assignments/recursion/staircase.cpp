#include <iostream>

int arr[] = {1,2,3};

int countSteps(int n ) {
    if (n == 0) {
        return 1;
    }
    int total = 0;
    for (int i = 0; i<3; i++) {
        if(n - arr[i] >= 0) {
            total += countSteps(n - arr[i]);
        }
    }
    return total;
    
}

int main()
{
   std::cout << "1 steps: " ;
   std::cout << countSteps(1) << std::endl;
   
   std::cout << "3 steps: " ;
   std::cout << countSteps(3) << std::endl;
   
   std::cout << "5 steps: " ;
   std::cout << countSteps(5) << std::endl;
   
   std::cout << "6 steps: " ;
   std::cout << countSteps(6) << std::endl;

    return 0;
}
