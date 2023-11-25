//
//  main.cpp
//  Practical OS
//
//  Created by Saharsh Wadekar on 21/11/23.
//

#include <iostream>

using namespace std;
struct Process {
        int alloc[3];
        int max[3];
        int need[3];
        bool clean = false;
};

int main(int argc, const char * argv[]) {
    int n;
    cout << "\nEnter Numbers of Processes :";
    cin >> n;
    Process p[n];
    int x = 0;
    int avail[3] = {0};
    int temp[3] = {0};
    bool fl = true;
    
    cout << "Processes\tAllocation\t\tMaximum\n\t\tA\tB\tC\tA\tB\tC\n";
    for(int i = 0 ; i < n ; i++){
            cout << "Process " << i+1 << " :\t" ;
            cin >> p[i].alloc[0]
                 >> p[i].alloc[1]
                 >> p[i].alloc[2]
                 >> p[i].max[0]
                 >> p[i].max[1]
                 >> p[i].max[2];
            temp[0] += p[i].alloc[0];
            temp[1] += p[i].alloc[1];
            temp[2] += p[i].alloc[2];
    }

    cout << endl << "Available : \t";
    cin >> avail[0] >> avail[1] >> avail[2];
    temp[0] += avail[0];
    temp[1] += avail[1];
    temp[2] += avail[2];
    cout << endl;

    //checking deadlock or unsafe
    for(int i = 0; i < n ; i++)
    {
            for(int j = 0; j < 3 ; j++)
            {
                    if (p[i].max[j] > temp[j]){
                            cout << "\nProcess Synchronization is UNSAFE";
                            exit(0);
                    }
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
                            cout << "P" << x+1 << " -> ";
                     }
            
            }
            x++;
            if(x>=n){
                    x = 0;
            }
            for(int i = 0 ; i < n; i++){
                if(p[i].clean == false)
                {
                    fl = false;
                }
            }
            if(fl)
            {
                cout << "EXIT\nExecution is Completed" << endl;
                break;
            }
    }
    
    return 0;
}



//Output

// Enter Numbers of Processes :5
// Processes       Allocation              Maximum
//                 A       B       C       A       B       C
// Process 1 :     0       1       0       7       5       3
// Process 2 :     2       0       0       3       2       2
// Process 3 :     3       0       2       9       0       2
// Process 4 :     2       1       1       2       2       2
// Process 5 :     0       0       2       4       3       3

// Available :     3       3       2

// P2 -> P4 -> P5 -> P1 -> P3 -> EXIT
// Execution is Completed
