#include <iostream>

int arr[] = {1,2,3};
int count[100];




int countSteps(int n ) {
    if (n == 0) {
        return 1;
    }
    int total = 0;
    if(count[n] != 0) {
   	return count[n];	
    }
    for (int i = 0; i<3; i++) {
        if(n - arr[i] >= 0) {
	    int t = countSteps(n - arr[i]);
            total += t;
	    count[n - arr[i]] = t; 
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
   
   std::cout << "35 steps: " ;
   std::cout << countSteps(35) << std::endl;

    return 0;

