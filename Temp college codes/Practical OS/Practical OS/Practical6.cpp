//
//  Practical6.cpp
//  Practical OS
//
//  Created by Saharsh Wadekar on 21/11/23.
//

#include "Practical6.hpp"
#include <iostream>
using namespace std;
struct Process {
        int alloc[3];
        int max[3];
        int need[3];
        bool clean = false;
        bool print =false;
};

int main()
{
        Process p[5];
        int x = 0;
        
        int avail[3];
        avail[0] = 3;
        avail[1] = 3;
        avail[2] = 2;
        
        int temp[3];
        temp[0] = 3;
        temp[1] = 3;
        temp[2] = 2;
        
        
        p[0].alloc[0] = 0;
        p[0].alloc[1] = 1;
        p[0].alloc[2] = 0;
        p[0].max[0] = 7;
        p[0].max[1] = 5;
        p[0].max[2] = 3;
        
        p[1].alloc[0] = 2;
        p[1].alloc[1] = 0;
        p[1].alloc[2] = 0;
        p[1].max[0] = 3;
        p[1].max[1] = 2;
        p[1].max[2] = 2;
        
        p[2].alloc[0] = 3;
        p[2].alloc[1] = 0;
        p[2].alloc[2] = 2;
        p[2].max[0] = 9;
        p[2].max[1] = 0;
        p[2].max[2] = 2;
        
        p[3].alloc[0] = 2;
        p[3].alloc[1] = 1;
        p[3].alloc[2] = 1;
        p[3].max[0] = 2;
        p[3].max[1] = 2;
        p[3].max[2] = 2;
        
        p[4].alloc[0] = 0;
        p[4].alloc[1] = 0;
        p[4].alloc[2] = 2;
        p[4].max[0] = 4;
        p[4].max[1] = 3;
        p[4].max[2] = 3;
        
        for(int i = 0; i < 5 ; i++)
        {
                for(int j = 0; j < 3 ; j++)
                {
                        temp[j] += p[i].alloc[j];
                }
        }
        
        //checking deadlock or unsafe
        bool unsafe = false;
        for(int i = 0; i < 5 ; i++)
        {
                for(int j = 0; j < 3 ; j++)
                {
                        if (p[i].max[j] > temp[j]){
                                unsafe = true;
                                break;
                        }
                }
        }
        if(unsafe){
                cout << "Process Synchronization is UNSAFE";
                exit(0);
        }
        
        for(int i = 0; i < 5 ; i++)
        {
                for(int j = 0; j < 3 ; j++)
                {
                        p[i].need[j] = p[i].max[j] - p[i].alloc[j];
                }
        }
        
        while(1){
                if(p[x].clean == false){
                        if((p[x].need[0] <= avail[0]) &&
                                (p[x].need[1] <= avail[1]) &&
                                (p[x].need[2] <= avail[2])){
                        
                                avail[0] += p[x].alloc[0];
                                avail[1] += p[x].alloc[1];
                                avail[2] += p[x].alloc[2];
                                p[x].clean = true;
                         }
                
                }
                if(p[x].clean == true && p[x].print == false ){
                        cout << "P" << x+1 << " -> ";
                        p[x].print = true;
                }
                x++;
                if(x>4){
                        x = 0;
                }
                if(p[0].print && p[1].print && p[2].print && p[3].print && p[4].print)
                {
                    cout << "\nExecution is Completed" << endl;
                    break;
                }
        }
        
        return 0;
}
