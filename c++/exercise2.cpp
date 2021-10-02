/////////////////////////////////////////////////////////////////////////////////////////////
//  _____                                        _                   
// |_   _|                                      / |_                 
//   | |   _ .--.   .--.  _ .--.   .---.  .---.`| |-' .--.   _ .--.  
//   | |  [ `.-. | ( (`\][ '/'`\ \/ /__\\/ /'`\]| | / .'`\ \[ `/'`\] 
//  _| |_  | | | |  `'.'. | \__/ || \__.,| \__. | |,| \__. | | |     
// |_____|[___||__][\__) )| ;.__/  '.__.''.___.'\__/ '.__.' [___]    
//                       [__|                                        
// 
// Create a program capable of summing element-by-element two equally long std::vectors.
// The sum can happen in a sequential or parallel way. The latter is a bonus.
// The result must be returned in the form of another std::vector.
//
// Keep track of the progress by logging the status to stdout. No constraints are given
// on the logging format (you can use multi lines, a progres bar or anything you want).
//
// The peculiarity of this exercise is that the status logging has to be performed by 
// another thread with respect to the one (or the ones) performing the sum.
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <thread>
#include <vector>
#define pb push_back
using namespace std;
#include <stdio.h>
#include <fstream>
#include <string>



vector<int> v3;

void calcSum(vector<int> v1, vector<int> v2)
{
    for(int j=0; j<v1.size();j++)
        v3.pb(v1[j]+v2[j]);
}

void logger(int n)
{

    for(int j=0; j<n;)
    {
    	int barWidth = 70;
    	if(j<v3.size())
	    	std::cout << "[";
	    	float progres = j/float(n);
	    	int pos = barWidth * progres;

	    	for (int i = 0; i < barWidth; ++i) {
		        if (i < pos) std::cout << "=";
		        else if (i == pos) std::cout << ">";
		        else std::cout << " ";
		    }

		    std::cout << "] " << int(progres * 100.0) << " %\r";
	    	std::cout.flush();
	    	j++;


        // if(j<v3.size())
        //     cout<<v3[j]<<' ',j++;
        // else ;
    }
}

int main()
{	

	freopen("./output.txt", "w", stdout);
    int x,n=100;
    // vector<int> v1 = {1,2,3,4,5};
    // vector<int> v2 = {1,2,3,4,5};




    vector<int> v1(n, 0);
    vector<int> v2(n, 0);

    srand(time(0));
    generate(v1.begin(), v2.end(), rand); 
    generate(v1.begin(), v2.end(), rand); 

    thread t1(calcSum,v1,v2);
    thread t2(logger,n);

    t1.join();
    t2.join();

  	cout<<"Final Sum Array: ";
    for(int i=0; i<n;i++)
        cout<<v3[i]<<' ',i++;
}